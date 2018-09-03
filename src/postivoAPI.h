#ifndef POSTIVO_API_H
#define POSTIVO_API_H

#include "soap/soapH.h"

/// <global instances>
extern struct soap * g_soap;
/// </global instances>

/// <functions>
void initPostivoAPI();
void closePostivoAPI();

void postDispatch(const char * login, const char * password);
void postGetDispatchStatus(const char * login,const char * password);
void postGetBalance(const char * login, const char * password);
void postGetPrice(const char * login, const char * password);
void postGetConfigProfiles();
void postGetSenders();
void postGetCertificate();
void postAddSender();
void postVerifySender();
void postVerifySenderID();
/// </functions>

#endif
