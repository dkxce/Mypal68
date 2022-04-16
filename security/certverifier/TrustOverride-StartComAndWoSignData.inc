// /C=CN/O=WoSign CA Limited/CN=CA \xE6\xB2\x83\xE9\x80\x9A\xE6\xA0\xB9\xE8\xAF\x81\xE4\xB9\xA6
// Using a consistent naming convention, this would actually be called
// 'CA沃通根证书DN', but since GCC 6.2.1 apparently can't handle UTF-8
// identifiers, this will have to do.
static const uint8_t CAWoSignRootDN[72] = {
  0x30, 0x46, 0x31, 0x0B, 0x30, 0x09, 0x06, 0x03, 0x55, 0x04, 0x06, 0x13, 0x02,
  0x43, 0x4E, 0x31, 0x1A, 0x30, 0x18, 0x06, 0x03, 0x55, 0x04, 0x0A, 0x13, 0x11,
  0x57, 0x6F, 0x53, 0x69, 0x67, 0x6E, 0x20, 0x43, 0x41, 0x20, 0x4C, 0x69, 0x6D,
  0x69, 0x74, 0x65, 0x64, 0x31, 0x1B, 0x30, 0x19, 0x06, 0x03, 0x55, 0x04, 0x03,
  0x0C, 0x12, 0x43, 0x41, 0x20, 0xE6, 0xB2, 0x83, 0xE9, 0x80, 0x9A, 0xE6, 0xA0,
  0xB9, 0xE8, 0xAF, 0x81, 0xE4, 0xB9, 0xA6,
};

// /C=CN/O=WoSign CA Limited/CN=CA WoSign ECC Root
static const uint8_t CAWoSignECCRootDN[72] = {
  0x30, 0x46, 0x31, 0x0B, 0x30, 0x09, 0x06, 0x03, 0x55, 0x04, 0x06, 0x13, 0x02,
  0x43, 0x4E, 0x31, 0x1A, 0x30, 0x18, 0x06, 0x03, 0x55, 0x04, 0x0A, 0x13, 0x11,
  0x57, 0x6F, 0x53, 0x69, 0x67, 0x6E, 0x20, 0x43, 0x41, 0x20, 0x4C, 0x69, 0x6D,
  0x69, 0x74, 0x65, 0x64, 0x31, 0x1B, 0x30, 0x19, 0x06, 0x03, 0x55, 0x04, 0x03,
  0x13, 0x12, 0x43, 0x41, 0x20, 0x57, 0x6F, 0x53, 0x69, 0x67, 0x6E, 0x20, 0x45,
  0x43, 0x43, 0x20, 0x52, 0x6F, 0x6F, 0x74,
};

// /C=CN/O=WoSign CA Limited/CN=Certification Authority of WoSign
static const uint8_t CertificationAuthorityofWoSignDN[87] = {
  0x30, 0x55, 0x31, 0x0B, 0x30, 0x09, 0x06, 0x03, 0x55, 0x04, 0x06, 0x13, 0x02,
  0x43, 0x4E, 0x31, 0x1A, 0x30, 0x18, 0x06, 0x03, 0x55, 0x04, 0x0A, 0x13, 0x11,
  0x57, 0x6F, 0x53, 0x69, 0x67, 0x6E, 0x20, 0x43, 0x41, 0x20, 0x4C, 0x69, 0x6D,
  0x69, 0x74, 0x65, 0x64, 0x31, 0x2A, 0x30, 0x28, 0x06, 0x03, 0x55, 0x04, 0x03,
  0x13, 0x21, 0x43, 0x65, 0x72, 0x74, 0x69, 0x66, 0x69, 0x63, 0x61, 0x74, 0x69,
  0x6F, 0x6E, 0x20, 0x41, 0x75, 0x74, 0x68, 0x6F, 0x72, 0x69, 0x74, 0x79, 0x20,
  0x6F, 0x66, 0x20, 0x57, 0x6F, 0x53, 0x69, 0x67, 0x6E,
};

// /C=CN/O=WoSign CA Limited/CN=Certification Authority of WoSign G2
static const uint8_t CertificationAuthorityofWoSignG2DN[90] = {
  0x30, 0x58, 0x31, 0x0B, 0x30, 0x09, 0x06, 0x03, 0x55, 0x04, 0x06, 0x13, 0x02,
  0x43, 0x4E, 0x31, 0x1A, 0x30, 0x18, 0x06, 0x03, 0x55, 0x04, 0x0A, 0x13, 0x11,
  0x57, 0x6F, 0x53, 0x69, 0x67, 0x6E, 0x20, 0x43, 0x41, 0x20, 0x4C, 0x69, 0x6D,
  0x69, 0x74, 0x65, 0x64, 0x31, 0x2D, 0x30, 0x2B, 0x06, 0x03, 0x55, 0x04, 0x03,
  0x13, 0x24, 0x43, 0x65, 0x72, 0x74, 0x69, 0x66, 0x69, 0x63, 0x61, 0x74, 0x69,
  0x6F, 0x6E, 0x20, 0x41, 0x75, 0x74, 0x68, 0x6F, 0x72, 0x69, 0x74, 0x79, 0x20,
  0x6F, 0x66, 0x20, 0x57, 0x6F, 0x53, 0x69, 0x67, 0x6E, 0x20, 0x47, 0x32,
};

// /C=IL/O=StartCom Ltd./OU=Secure Digital Certificate Signing/CN=StartCom Certification Authority
static const uint8_t StartComCertificationAuthorityDN[127] = {
  0x30, 0x7D, 0x31, 0x0B, 0x30, 0x09, 0x06, 0x03, 0x55, 0x04, 0x06, 0x13, 0x02,
  0x49, 0x4C, 0x31, 0x16, 0x30, 0x14, 0x06, 0x03, 0x55, 0x04, 0x0A, 0x13, 0x0D,
  0x53, 0x74, 0x61, 0x72, 0x74, 0x43, 0x6F, 0x6D, 0x20, 0x4C, 0x74, 0x64, 0x2E,
  0x31, 0x2B, 0x30, 0x29, 0x06, 0x03, 0x55, 0x04, 0x0B, 0x13, 0x22, 0x53, 0x65,
  0x63, 0x75, 0x72, 0x65, 0x20, 0x44, 0x69, 0x67, 0x69, 0x74, 0x61, 0x6C, 0x20,
  0x43, 0x65, 0x72, 0x74, 0x69, 0x66, 0x69, 0x63, 0x61, 0x74, 0x65, 0x20, 0x53,
  0x69, 0x67, 0x6E, 0x69, 0x6E, 0x67, 0x31, 0x29, 0x30, 0x27, 0x06, 0x03, 0x55,
  0x04, 0x03, 0x13, 0x20, 0x53, 0x74, 0x61, 0x72, 0x74, 0x43, 0x6F, 0x6D, 0x20,
  0x43, 0x65, 0x72, 0x74, 0x69, 0x66, 0x69, 0x63, 0x61, 0x74, 0x69, 0x6F, 0x6E,
  0x20, 0x41, 0x75, 0x74, 0x68, 0x6F, 0x72, 0x69, 0x74, 0x79,
};

// /C=IL/O=StartCom Ltd./CN=StartCom Certification Authority G2
static const uint8_t StartComCertificationAuthorityG2DN[85] = {
  0x30, 0x53, 0x31, 0x0B, 0x30, 0x09, 0x06, 0x03, 0x55, 0x04, 0x06, 0x13, 0x02,
  0x49, 0x4C, 0x31, 0x16, 0x30, 0x14, 0x06, 0x03, 0x55, 0x04, 0x0A, 0x13, 0x0D,
  0x53, 0x74, 0x61, 0x72, 0x74, 0x43, 0x6F, 0x6D, 0x20, 0x4C, 0x74, 0x64, 0x2E,
  0x31, 0x2C, 0x30, 0x2A, 0x06, 0x03, 0x55, 0x04, 0x03, 0x13, 0x23, 0x53, 0x74,
  0x61, 0x72, 0x74, 0x43, 0x6F, 0x6D, 0x20, 0x43, 0x65, 0x72, 0x74, 0x69, 0x66,
  0x69, 0x63, 0x61, 0x74, 0x69, 0x6F, 0x6E, 0x20, 0x41, 0x75, 0x74, 0x68, 0x6F,
  0x72, 0x69, 0x74, 0x79, 0x20, 0x47, 0x32,
};

static const DataAndLength StartComAndWoSignDNs[]= {
 { CAWoSignRootDN,
   sizeof(CAWoSignRootDN) },
 { CAWoSignECCRootDN,
   sizeof(CAWoSignECCRootDN) },
 { CertificationAuthorityofWoSignDN,
   sizeof(CertificationAuthorityofWoSignDN) },
 { CertificationAuthorityofWoSignG2DN,
   sizeof(CertificationAuthorityofWoSignG2DN) },
 { StartComCertificationAuthorityDN,
   sizeof(StartComCertificationAuthorityDN) },
 { StartComCertificationAuthorityG2DN,
   sizeof(StartComCertificationAuthorityG2DN) },
};