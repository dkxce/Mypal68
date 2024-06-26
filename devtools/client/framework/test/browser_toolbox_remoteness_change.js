/* Any copyright is dedicated to the Public Domain.
 * http://creativecommons.org/publicdomain/zero/1.0/ */

const URL_1 = "about:robots";
const URL_2 =
  "data:text/html;charset=UTF-8," +
  encodeURIComponent('<div id="remote-page">foo</div>');

add_task(async function() {
  info("Open a tab on a URL supporting only running in parent process");
  const tab = await addTab(URL_1);
  is(
    tab.linkedBrowser.currentURI.spec,
    URL_1,
    "We really are on the expected document"
  );
  is(
    tab.linkedBrowser.getAttribute("remote"),
    "",
    "And running in parent process"
  );

  let toolbox = await openToolboxForTab(tab);

  const onToolboxDestroyed = toolbox.once("destroyed");
  const onToolboxCreated = gDevTools.once("toolbox-created");

  info("Navigate to a URL supporting remote process");
  const onLoaded = BrowserTestUtils.browserLoaded(tab.linkedBrowser);
  BrowserTestUtils.loadURI(gBrowser, URL_2);
  await onLoaded;

  is(
    tab.linkedBrowser.getAttribute("remote"),
    "true",
    "Navigated to a data: URI and switching to remote"
  );

  info("Waiting for the toolbox to be destroyed");
  await onToolboxDestroyed;

  info("Waiting for a new toolbox to be created");
  toolbox = await onToolboxCreated;

  info("Waiting for the new toolbox to be ready");
  await toolbox.once("ready");

  info("Veryify we are inspecting the new document");
  const console = await toolbox.selectTool("webconsole");
  const { ui } = console.hud;
  ui.wrapper.dispatchEvaluateExpression("document.location.href");
  await waitUntil(() => ui.outputNode.querySelector(".result"));
  const url = ui.outputNode.querySelector(".result");

  ok(
    url.textContent.includes(URL_2),
    "The console inspects the second document"
  );
});
