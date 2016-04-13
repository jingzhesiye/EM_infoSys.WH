/* soapDetectServiceHttpBindingProxy.cpp
   Generated by gSOAP 2.8.21 from mds.h

Copyright(C) 2000-2014, Robert van Engelen, Genivia Inc. All Rights Reserved.
The generated code is released under one of the following licenses:
GPL or Genivia's license for commercial use.
This program is released under the GPL with the additional exemption that
compiling, linking, and/or using OpenSSL is allowed.
*/

#include "soapDetectServiceHttpBindingProxy.h"

DetectServiceHttpBindingProxy::DetectServiceHttpBindingProxy()
{	DetectServiceHttpBindingProxy_init(SOAP_IO_DEFAULT, SOAP_IO_DEFAULT);
}

DetectServiceHttpBindingProxy::DetectServiceHttpBindingProxy(const struct soap &_soap) : soap(_soap)
{ }

DetectServiceHttpBindingProxy::DetectServiceHttpBindingProxy(const char *url)
{	DetectServiceHttpBindingProxy_init(SOAP_IO_DEFAULT, SOAP_IO_DEFAULT);
	soap_endpoint = url;
}

DetectServiceHttpBindingProxy::DetectServiceHttpBindingProxy(soap_mode iomode)
{	DetectServiceHttpBindingProxy_init(iomode, iomode);
}

DetectServiceHttpBindingProxy::DetectServiceHttpBindingProxy(const char *url, soap_mode iomode)
{	DetectServiceHttpBindingProxy_init(iomode, iomode);
	soap_endpoint = url;
}

DetectServiceHttpBindingProxy::DetectServiceHttpBindingProxy(soap_mode imode, soap_mode omode)
{	DetectServiceHttpBindingProxy_init(imode, omode);
}

DetectServiceHttpBindingProxy::~DetectServiceHttpBindingProxy()
{ }

void DetectServiceHttpBindingProxy::DetectServiceHttpBindingProxy_init(soap_mode imode, soap_mode omode)
{	soap_imode(this, imode);
	soap_omode(this, omode);
	soap_endpoint = NULL;
	static const struct Namespace namespaces[] =
{
	{"SOAP-ENV", "http://schemas.xmlsoap.org/soap/envelope/", "http://www.w3.org/*/soap-envelope", NULL},
	{"SOAP-ENC", "http://schemas.xmlsoap.org/soap/encoding/", "http://www.w3.org/*/soap-encoding", NULL},
	{"xsi", "http://www.w3.org/2001/XMLSchema-instance", "http://www.w3.org/*/XMLSchema-instance", NULL},
	{"xsd", "http://www.w3.org/2001/XMLSchema", "http://www.w3.org/*/XMLSchema", NULL},
	{"ns1", "http://webservice.mpac.nari.com", NULL, NULL},
	{NULL, NULL, NULL, NULL}
};
	soap_set_namespaces(this, namespaces);
}

void DetectServiceHttpBindingProxy::destroy()
{	soap_destroy(this);
	soap_end(this);
}

void DetectServiceHttpBindingProxy::reset()
{	destroy();
	soap_done(this);
	soap_initialize(this);
	DetectServiceHttpBindingProxy_init(SOAP_IO_DEFAULT, SOAP_IO_DEFAULT);
}

void DetectServiceHttpBindingProxy::soap_noheader()
{	this->header = NULL;
}

const SOAP_ENV__Header *DetectServiceHttpBindingProxy::soap_header()
{	return this->header;
}

const SOAP_ENV__Fault *DetectServiceHttpBindingProxy::soap_fault()
{	return this->fault;
}

const char *DetectServiceHttpBindingProxy::soap_fault_string()
{	return *soap_faultstring(this);
}

const char *DetectServiceHttpBindingProxy::soap_fault_detail()
{	return *soap_faultdetail(this);
}

int DetectServiceHttpBindingProxy::soap_close_socket()
{	return soap_closesock(this);
}

int DetectServiceHttpBindingProxy::soap_force_close_socket()
{	return soap_force_closesock(this);
}

void DetectServiceHttpBindingProxy::soap_print_fault(FILE *fd)
{	::soap_print_fault(this, fd);
}

#ifndef WITH_LEAN
#ifndef WITH_COMPAT
void DetectServiceHttpBindingProxy::soap_stream_fault(std::ostream& os)
{	::soap_stream_fault(this, os);
}
#endif

char *DetectServiceHttpBindingProxy::soap_sprint_fault(char *buf, size_t len)
{	return ::soap_sprint_fault(this, buf, len);
}
#endif

int DetectServiceHttpBindingProxy::getSealInfo(const char *endpoint, const char *soap_action, _ns1__getSealInfo *ns1__getSealInfo, _ns1__getSealInfoResponse &ns1__getSealInfoResponse)
{	struct soap *soap = this;
	struct __ns1__getSealInfo soap_tmp___ns1__getSealInfo;
	if (endpoint)
		soap_endpoint = endpoint;
	if (soap_endpoint == NULL)
		soap_endpoint = "http://10.158.249.98:7012/InterfaceWS/InterfaceBusiness/services/DetectService";
	if (soap_action == NULL)
		soap_action = "";
	soap_begin(soap);
	soap->encodingStyle = NULL;
	soap_tmp___ns1__getSealInfo.ns1__getSealInfo = ns1__getSealInfo;
	soap_serializeheader(soap);
	soap_serialize___ns1__getSealInfo(soap, &soap_tmp___ns1__getSealInfo);
	if (soap_begin_count(soap))
		return soap->error;
	if (soap->mode & SOAP_IO_LENGTH)
	{	if (soap_envelope_begin_out(soap)
		 || soap_putheader(soap)
		 || soap_body_begin_out(soap)
		 || soap_put___ns1__getSealInfo(soap, &soap_tmp___ns1__getSealInfo, "-ns1:getSealInfo", NULL)
		 || soap_body_end_out(soap)
		 || soap_envelope_end_out(soap))
			 return soap->error;
	}
	if (soap_end_count(soap))
		return soap->error;
	if (soap_connect(soap, soap_url(soap, soap_endpoint, NULL), soap_action)
	 || soap_envelope_begin_out(soap)
	 || soap_putheader(soap)
	 || soap_body_begin_out(soap)
	 || soap_put___ns1__getSealInfo(soap, &soap_tmp___ns1__getSealInfo, "-ns1:getSealInfo", NULL)
	 || soap_body_end_out(soap)
	 || soap_envelope_end_out(soap)
	 || soap_end_send(soap))
		return soap_closesock(soap);
	if (!&ns1__getSealInfoResponse)
		return soap_closesock(soap);
	ns1__getSealInfoResponse.soap_default(soap);
	if (soap_begin_recv(soap)
	 || soap_envelope_begin_in(soap)
	 || soap_recv_header(soap)
	 || soap_body_begin_in(soap))
		return soap_closesock(soap);
	ns1__getSealInfoResponse.soap_get(soap, "ns1:getSealInfoResponse", NULL);
	if (soap->error)
		return soap_recv_fault(soap, 0);
	if (soap_body_end_in(soap)
	 || soap_envelope_end_in(soap)
	 || soap_end_recv(soap))
		return soap_closesock(soap);
	return soap_closesock(soap);
}

int DetectServiceHttpBindingProxy::uploadLabel(const char *endpoint, const char *soap_action, _ns1__uploadLabel *ns1__uploadLabel, _ns1__uploadLabelResponse &ns1__uploadLabelResponse)
{	struct soap *soap = this;
	struct __ns1__uploadLabel soap_tmp___ns1__uploadLabel;
	if (endpoint)
		soap_endpoint = endpoint;
	if (soap_endpoint == NULL)
		soap_endpoint = "http://10.158.249.98:7012/InterfaceWS/InterfaceBusiness/services/DetectService";
	if (soap_action == NULL)
		soap_action = "";
	soap_begin(soap);
	soap->encodingStyle = NULL;
	soap_tmp___ns1__uploadLabel.ns1__uploadLabel = ns1__uploadLabel;
	soap_serializeheader(soap);
	soap_serialize___ns1__uploadLabel(soap, &soap_tmp___ns1__uploadLabel);
	if (soap_begin_count(soap))
		return soap->error;
	if (soap->mode & SOAP_IO_LENGTH)
	{	if (soap_envelope_begin_out(soap)
		 || soap_putheader(soap)
		 || soap_body_begin_out(soap)
		 || soap_put___ns1__uploadLabel(soap, &soap_tmp___ns1__uploadLabel, "-ns1:uploadLabel", NULL)
		 || soap_body_end_out(soap)
		 || soap_envelope_end_out(soap))
			 return soap->error;
	}
	if (soap_end_count(soap))
		return soap->error;
	if (soap_connect(soap, soap_url(soap, soap_endpoint, NULL), soap_action)
	 || soap_envelope_begin_out(soap)
	 || soap_putheader(soap)
	 || soap_body_begin_out(soap)
	 || soap_put___ns1__uploadLabel(soap, &soap_tmp___ns1__uploadLabel, "-ns1:uploadLabel", NULL)
	 || soap_body_end_out(soap)
	 || soap_envelope_end_out(soap)
	 || soap_end_send(soap))
		return soap_closesock(soap);
	if (!&ns1__uploadLabelResponse)
		return soap_closesock(soap);
	ns1__uploadLabelResponse.soap_default(soap);
	if (soap_begin_recv(soap)
	 || soap_envelope_begin_in(soap)
	 || soap_recv_header(soap)
	 || soap_body_begin_in(soap))
		return soap_closesock(soap);
	ns1__uploadLabelResponse.soap_get(soap, "ns1:uploadLabelResponse", NULL);
	if (soap->error)
		return soap_recv_fault(soap, 0);
	if (soap_body_end_in(soap)
	 || soap_envelope_end_in(soap)
	 || soap_end_recv(soap))
		return soap_closesock(soap);
	return soap_closesock(soap);
}

int DetectServiceHttpBindingProxy::sendCtrlTaskFinishFlag(const char *endpoint, const char *soap_action, _ns1__sendCtrlTaskFinishFlag *ns1__sendCtrlTaskFinishFlag, _ns1__sendCtrlTaskFinishFlagResponse &ns1__sendCtrlTaskFinishFlagResponse)
{	struct soap *soap = this;
	struct __ns1__sendCtrlTaskFinishFlag soap_tmp___ns1__sendCtrlTaskFinishFlag;
	if (endpoint)
		soap_endpoint = endpoint;
	if (soap_endpoint == NULL)
		soap_endpoint = "http://10.158.249.98:7012/InterfaceWS/InterfaceBusiness/services/DetectService";
	if (soap_action == NULL)
		soap_action = "";
	soap_begin(soap);
	soap->encodingStyle = NULL;
	soap_tmp___ns1__sendCtrlTaskFinishFlag.ns1__sendCtrlTaskFinishFlag = ns1__sendCtrlTaskFinishFlag;
	soap_serializeheader(soap);
	soap_serialize___ns1__sendCtrlTaskFinishFlag(soap, &soap_tmp___ns1__sendCtrlTaskFinishFlag);
	if (soap_begin_count(soap))
		return soap->error;
	if (soap->mode & SOAP_IO_LENGTH)
	{	if (soap_envelope_begin_out(soap)
		 || soap_putheader(soap)
		 || soap_body_begin_out(soap)
		 || soap_put___ns1__sendCtrlTaskFinishFlag(soap, &soap_tmp___ns1__sendCtrlTaskFinishFlag, "-ns1:sendCtrlTaskFinishFlag", NULL)
		 || soap_body_end_out(soap)
		 || soap_envelope_end_out(soap))
			 return soap->error;
	}
	if (soap_end_count(soap))
		return soap->error;
	if (soap_connect(soap, soap_url(soap, soap_endpoint, NULL), soap_action)
	 || soap_envelope_begin_out(soap)
	 || soap_putheader(soap)
	 || soap_body_begin_out(soap)
	 || soap_put___ns1__sendCtrlTaskFinishFlag(soap, &soap_tmp___ns1__sendCtrlTaskFinishFlag, "-ns1:sendCtrlTaskFinishFlag", NULL)
	 || soap_body_end_out(soap)
	 || soap_envelope_end_out(soap)
	 || soap_end_send(soap))
		return soap_closesock(soap);
	if (!&ns1__sendCtrlTaskFinishFlagResponse)
		return soap_closesock(soap);
	ns1__sendCtrlTaskFinishFlagResponse.soap_default(soap);
	if (soap_begin_recv(soap)
	 || soap_envelope_begin_in(soap)
	 || soap_recv_header(soap)
	 || soap_body_begin_in(soap))
		return soap_closesock(soap);
	ns1__sendCtrlTaskFinishFlagResponse.soap_get(soap, "ns1:sendCtrlTaskFinishFlagResponse", NULL);
	if (soap->error)
		return soap_recv_fault(soap, 0);
	if (soap_body_end_in(soap)
	 || soap_envelope_end_in(soap)
	 || soap_end_recv(soap))
		return soap_closesock(soap);
	return soap_closesock(soap);
}

int DetectServiceHttpBindingProxy::uploadSealsCode(const char *endpoint, const char *soap_action, _ns1__uploadSealsCode *ns1__uploadSealsCode, _ns1__uploadSealsCodeResponse &ns1__uploadSealsCodeResponse)
{	struct soap *soap = this;
	struct __ns1__uploadSealsCode soap_tmp___ns1__uploadSealsCode;
	if (endpoint)
		soap_endpoint = endpoint;
	if (soap_endpoint == NULL)
		soap_endpoint = "http://10.158.249.98:7012/InterfaceWS/InterfaceBusiness/services/DetectService";
	if (soap_action == NULL)
		soap_action = "";
	soap_begin(soap);
	soap->encodingStyle = NULL;
	soap_tmp___ns1__uploadSealsCode.ns1__uploadSealsCode = ns1__uploadSealsCode;
	soap_serializeheader(soap);
	soap_serialize___ns1__uploadSealsCode(soap, &soap_tmp___ns1__uploadSealsCode);
	if (soap_begin_count(soap))
		return soap->error;
	if (soap->mode & SOAP_IO_LENGTH)
	{	if (soap_envelope_begin_out(soap)
		 || soap_putheader(soap)
		 || soap_body_begin_out(soap)
		 || soap_put___ns1__uploadSealsCode(soap, &soap_tmp___ns1__uploadSealsCode, "-ns1:uploadSealsCode", NULL)
		 || soap_body_end_out(soap)
		 || soap_envelope_end_out(soap))
			 return soap->error;
	}
	if (soap_end_count(soap))
		return soap->error;
	if (soap_connect(soap, soap_url(soap, soap_endpoint, NULL), soap_action)
	 || soap_envelope_begin_out(soap)
	 || soap_putheader(soap)
	 || soap_body_begin_out(soap)
	 || soap_put___ns1__uploadSealsCode(soap, &soap_tmp___ns1__uploadSealsCode, "-ns1:uploadSealsCode", NULL)
	 || soap_body_end_out(soap)
	 || soap_envelope_end_out(soap)
	 || soap_end_send(soap))
		return soap_closesock(soap);
	if (!&ns1__uploadSealsCodeResponse)
		return soap_closesock(soap);
	ns1__uploadSealsCodeResponse.soap_default(soap);
	if (soap_begin_recv(soap)
	 || soap_envelope_begin_in(soap)
	 || soap_recv_header(soap)
	 || soap_body_begin_in(soap))
		return soap_closesock(soap);
	ns1__uploadSealsCodeResponse.soap_get(soap, "ns1:uploadSealsCodeResponse", NULL);
	if (soap->error)
		return soap_recv_fault(soap, 0);
	if (soap_body_end_in(soap)
	 || soap_envelope_end_in(soap)
	 || soap_end_recv(soap))
		return soap_closesock(soap);
	return soap_closesock(soap);
}

int DetectServiceHttpBindingProxy::sendTaskFinishFlag(const char *endpoint, const char *soap_action, _ns1__sendTaskFinishFlag *ns1__sendTaskFinishFlag, _ns1__sendTaskFinishFlagResponse &ns1__sendTaskFinishFlagResponse)
{	struct soap *soap = this;
	struct __ns1__sendTaskFinishFlag soap_tmp___ns1__sendTaskFinishFlag;
	if (endpoint)
		soap_endpoint = endpoint;
	if (soap_endpoint == NULL)
		soap_endpoint = "http://10.158.249.98:7012/InterfaceWS/InterfaceBusiness/services/DetectService";
	if (soap_action == NULL)
		soap_action = "";
	soap_begin(soap);
	soap->encodingStyle = NULL;
	soap_tmp___ns1__sendTaskFinishFlag.ns1__sendTaskFinishFlag = ns1__sendTaskFinishFlag;
	soap_serializeheader(soap);
	soap_serialize___ns1__sendTaskFinishFlag(soap, &soap_tmp___ns1__sendTaskFinishFlag);
	if (soap_begin_count(soap))
		return soap->error;
	if (soap->mode & SOAP_IO_LENGTH)
	{	if (soap_envelope_begin_out(soap)
		 || soap_putheader(soap)
		 || soap_body_begin_out(soap)
		 || soap_put___ns1__sendTaskFinishFlag(soap, &soap_tmp___ns1__sendTaskFinishFlag, "-ns1:sendTaskFinishFlag", NULL)
		 || soap_body_end_out(soap)
		 || soap_envelope_end_out(soap))
			 return soap->error;
	}
	if (soap_end_count(soap))
		return soap->error;
	if (soap_connect(soap, soap_url(soap, soap_endpoint, NULL), soap_action)
	 || soap_envelope_begin_out(soap)
	 || soap_putheader(soap)
	 || soap_body_begin_out(soap)
	 || soap_put___ns1__sendTaskFinishFlag(soap, &soap_tmp___ns1__sendTaskFinishFlag, "-ns1:sendTaskFinishFlag", NULL)
	 || soap_body_end_out(soap)
	 || soap_envelope_end_out(soap)
	 || soap_end_send(soap))
		return soap_closesock(soap);
	if (!&ns1__sendTaskFinishFlagResponse)
		return soap_closesock(soap);
	ns1__sendTaskFinishFlagResponse.soap_default(soap);
	if (soap_begin_recv(soap)
	 || soap_envelope_begin_in(soap)
	 || soap_recv_header(soap)
	 || soap_body_begin_in(soap))
		return soap_closesock(soap);
	ns1__sendTaskFinishFlagResponse.soap_get(soap, "ns1:sendTaskFinishFlagResponse", NULL);
	if (soap->error)
		return soap_recv_fault(soap, 0);
	if (soap_body_end_in(soap)
	 || soap_envelope_end_in(soap)
	 || soap_end_recv(soap))
		return soap_closesock(soap);
	return soap_closesock(soap);
}

int DetectServiceHttpBindingProxy::applyAssistEquip(const char *endpoint, const char *soap_action, _ns1__applyAssistEquip *ns1__applyAssistEquip, _ns1__applyAssistEquipResponse &ns1__applyAssistEquipResponse)
{	struct soap *soap = this;
	struct __ns1__applyAssistEquip soap_tmp___ns1__applyAssistEquip;
	if (endpoint)
		soap_endpoint = endpoint;
	if (soap_endpoint == NULL)
		soap_endpoint = "http://10.158.249.98:7012/InterfaceWS/InterfaceBusiness/services/DetectService";
	if (soap_action == NULL)
		soap_action = "";
	soap_begin(soap);
	soap->encodingStyle = NULL;
	soap_tmp___ns1__applyAssistEquip.ns1__applyAssistEquip = ns1__applyAssistEquip;
	soap_serializeheader(soap);
	soap_serialize___ns1__applyAssistEquip(soap, &soap_tmp___ns1__applyAssistEquip);
	if (soap_begin_count(soap))
		return soap->error;
	if (soap->mode & SOAP_IO_LENGTH)
	{	if (soap_envelope_begin_out(soap)
		 || soap_putheader(soap)
		 || soap_body_begin_out(soap)
		 || soap_put___ns1__applyAssistEquip(soap, &soap_tmp___ns1__applyAssistEquip, "-ns1:applyAssistEquip", NULL)
		 || soap_body_end_out(soap)
		 || soap_envelope_end_out(soap))
			 return soap->error;
	}
	if (soap_end_count(soap))
		return soap->error;
	if (soap_connect(soap, soap_url(soap, soap_endpoint, NULL), soap_action)
	 || soap_envelope_begin_out(soap)
	 || soap_putheader(soap)
	 || soap_body_begin_out(soap)
	 || soap_put___ns1__applyAssistEquip(soap, &soap_tmp___ns1__applyAssistEquip, "-ns1:applyAssistEquip", NULL)
	 || soap_body_end_out(soap)
	 || soap_envelope_end_out(soap)
	 || soap_end_send(soap))
		return soap_closesock(soap);
	if (!&ns1__applyAssistEquipResponse)
		return soap_closesock(soap);
	ns1__applyAssistEquipResponse.soap_default(soap);
	if (soap_begin_recv(soap)
	 || soap_envelope_begin_in(soap)
	 || soap_recv_header(soap)
	 || soap_body_begin_in(soap))
		return soap_closesock(soap);
	ns1__applyAssistEquipResponse.soap_get(soap, "ns1:applyAssistEquipResponse", NULL);
	if (soap->error)
		return soap_recv_fault(soap, 0);
	if (soap_body_end_in(soap)
	 || soap_envelope_end_in(soap)
	 || soap_end_recv(soap))
		return soap_closesock(soap);
	return soap_closesock(soap);
}

int DetectServiceHttpBindingProxy::getDETedTestData(const char *endpoint, const char *soap_action, _ns1__getDETedTestData *ns1__getDETedTestData, _ns1__getDETedTestDataResponse &ns1__getDETedTestDataResponse)
{	struct soap *soap = this;
	struct __ns1__getDETedTestData soap_tmp___ns1__getDETedTestData;
	if (endpoint)
		soap_endpoint = endpoint;
	if (soap_endpoint == NULL)
		soap_endpoint = "http://10.158.249.98:7012/InterfaceWS/InterfaceBusiness/services/DetectService";
	if (soap_action == NULL)
		soap_action = "";
	soap_begin(soap);
	soap->encodingStyle = NULL;
	soap_tmp___ns1__getDETedTestData.ns1__getDETedTestData = ns1__getDETedTestData;
	soap_serializeheader(soap);
	soap_serialize___ns1__getDETedTestData(soap, &soap_tmp___ns1__getDETedTestData);
	if (soap_begin_count(soap))
		return soap->error;
	if (soap->mode & SOAP_IO_LENGTH)
	{	if (soap_envelope_begin_out(soap)
		 || soap_putheader(soap)
		 || soap_body_begin_out(soap)
		 || soap_put___ns1__getDETedTestData(soap, &soap_tmp___ns1__getDETedTestData, "-ns1:getDETedTestData", NULL)
		 || soap_body_end_out(soap)
		 || soap_envelope_end_out(soap))
			 return soap->error;
	}
	if (soap_end_count(soap))
		return soap->error;
	if (soap_connect(soap, soap_url(soap, soap_endpoint, NULL), soap_action)
	 || soap_envelope_begin_out(soap)
	 || soap_putheader(soap)
	 || soap_body_begin_out(soap)
	 || soap_put___ns1__getDETedTestData(soap, &soap_tmp___ns1__getDETedTestData, "-ns1:getDETedTestData", NULL)
	 || soap_body_end_out(soap)
	 || soap_envelope_end_out(soap)
	 || soap_end_send(soap))
		return soap_closesock(soap);
	if (!&ns1__getDETedTestDataResponse)
		return soap_closesock(soap);
	ns1__getDETedTestDataResponse.soap_default(soap);
	if (soap_begin_recv(soap)
	 || soap_envelope_begin_in(soap)
	 || soap_recv_header(soap)
	 || soap_body_begin_in(soap))
		return soap_closesock(soap);
	ns1__getDETedTestDataResponse.soap_get(soap, "ns1:getDETedTestDataResponse", NULL);
	if (soap->error)
		return soap_recv_fault(soap, 0);
	if (soap_body_end_in(soap)
	 || soap_envelope_end_in(soap)
	 || soap_end_recv(soap))
		return soap_closesock(soap);
	return soap_closesock(soap);
}

int DetectServiceHttpBindingProxy::setResults(const char *endpoint, const char *soap_action, _ns1__setResults *ns1__setResults, _ns1__setResultsResponse &ns1__setResultsResponse)
{	struct soap *soap = this;
	struct __ns1__setResults soap_tmp___ns1__setResults;
	if (endpoint)
		soap_endpoint = endpoint;
	if (soap_endpoint == NULL)
		soap_endpoint = "http://10.158.249.98:7012/InterfaceWS/InterfaceBusiness/services/DetectService";
	if (soap_action == NULL)
		soap_action = "";
	soap_begin(soap);
	soap->encodingStyle = NULL;
	soap_tmp___ns1__setResults.ns1__setResults = ns1__setResults;
	soap_serializeheader(soap);
	soap_serialize___ns1__setResults(soap, &soap_tmp___ns1__setResults);
	if (soap_begin_count(soap))
		return soap->error;
	if (soap->mode & SOAP_IO_LENGTH)
	{	if (soap_envelope_begin_out(soap)
		 || soap_putheader(soap)
		 || soap_body_begin_out(soap)
		 || soap_put___ns1__setResults(soap, &soap_tmp___ns1__setResults, "-ns1:setResults", NULL)
		 || soap_body_end_out(soap)
		 || soap_envelope_end_out(soap))
			 return soap->error;
	}
	if (soap_end_count(soap))
		return soap->error;
	if (soap_connect(soap, soap_url(soap, soap_endpoint, NULL), soap_action)
	 || soap_envelope_begin_out(soap)
	 || soap_putheader(soap)
	 || soap_body_begin_out(soap)
	 || soap_put___ns1__setResults(soap, &soap_tmp___ns1__setResults, "-ns1:setResults", NULL)
	 || soap_body_end_out(soap)
	 || soap_envelope_end_out(soap)
	 || soap_end_send(soap))
		return soap_closesock(soap);
	if (!&ns1__setResultsResponse)
		return soap_closesock(soap);
	ns1__setResultsResponse.soap_default(soap);
	if (soap_begin_recv(soap)
	 || soap_envelope_begin_in(soap)
	 || soap_recv_header(soap)
	 || soap_body_begin_in(soap))
		return soap_closesock(soap);
	ns1__setResultsResponse.soap_get(soap, "ns1:setResultsResponse", NULL);
	if (soap->error)
		return soap_recv_fault(soap, 0);
	if (soap_body_end_in(soap)
	 || soap_envelope_end_in(soap)
	 || soap_end_recv(soap))
		return soap_closesock(soap);
	return soap_closesock(soap);
}

int DetectServiceHttpBindingProxy::getMachineHandInfo(const char *endpoint, const char *soap_action, _ns1__getMachineHandInfo *ns1__getMachineHandInfo, _ns1__getMachineHandInfoResponse &ns1__getMachineHandInfoResponse)
{	struct soap *soap = this;
	struct __ns1__getMachineHandInfo soap_tmp___ns1__getMachineHandInfo;
	if (endpoint)
		soap_endpoint = endpoint;
	if (soap_endpoint == NULL)
		soap_endpoint = "http://10.158.249.98:7012/InterfaceWS/InterfaceBusiness/services/DetectService";
	if (soap_action == NULL)
		soap_action = "";
	soap_begin(soap);
	soap->encodingStyle = NULL;
	soap_tmp___ns1__getMachineHandInfo.ns1__getMachineHandInfo = ns1__getMachineHandInfo;
	soap_serializeheader(soap);
	soap_serialize___ns1__getMachineHandInfo(soap, &soap_tmp___ns1__getMachineHandInfo);
	if (soap_begin_count(soap))
		return soap->error;
	if (soap->mode & SOAP_IO_LENGTH)
	{	if (soap_envelope_begin_out(soap)
		 || soap_putheader(soap)
		 || soap_body_begin_out(soap)
		 || soap_put___ns1__getMachineHandInfo(soap, &soap_tmp___ns1__getMachineHandInfo, "-ns1:getMachineHandInfo", NULL)
		 || soap_body_end_out(soap)
		 || soap_envelope_end_out(soap))
			 return soap->error;
	}
	if (soap_end_count(soap))
		return soap->error;
	if (soap_connect(soap, soap_url(soap, soap_endpoint, NULL), soap_action)
	 || soap_envelope_begin_out(soap)
	 || soap_putheader(soap)
	 || soap_body_begin_out(soap)
	 || soap_put___ns1__getMachineHandInfo(soap, &soap_tmp___ns1__getMachineHandInfo, "-ns1:getMachineHandInfo", NULL)
	 || soap_body_end_out(soap)
	 || soap_envelope_end_out(soap)
	 || soap_end_send(soap))
		return soap_closesock(soap);
	if (!&ns1__getMachineHandInfoResponse)
		return soap_closesock(soap);
	ns1__getMachineHandInfoResponse.soap_default(soap);
	if (soap_begin_recv(soap)
	 || soap_envelope_begin_in(soap)
	 || soap_recv_header(soap)
	 || soap_body_begin_in(soap))
		return soap_closesock(soap);
	ns1__getMachineHandInfoResponse.soap_get(soap, "ns1:getMachineHandInfoResponse", NULL);
	if (soap->error)
		return soap_recv_fault(soap, 0);
	if (soap_body_end_in(soap)
	 || soap_envelope_end_in(soap)
	 || soap_end_recv(soap))
		return soap_closesock(soap);
	return soap_closesock(soap);
}

int DetectServiceHttpBindingProxy::applyEquip(const char *endpoint, const char *soap_action, _ns1__applyEquip *ns1__applyEquip, _ns1__applyEquipResponse &ns1__applyEquipResponse)
{	struct soap *soap = this;
	struct __ns1__applyEquip soap_tmp___ns1__applyEquip;
	if (endpoint)
		soap_endpoint = endpoint;
	if (soap_endpoint == NULL)
		soap_endpoint = "http://10.158.249.98:7012/InterfaceWS/InterfaceBusiness/services/DetectService";
	if (soap_action == NULL)
		soap_action = "";
	soap_begin(soap);
	soap->encodingStyle = NULL;
	soap_tmp___ns1__applyEquip.ns1__applyEquip = ns1__applyEquip;
	soap_serializeheader(soap);
	soap_serialize___ns1__applyEquip(soap, &soap_tmp___ns1__applyEquip);
	if (soap_begin_count(soap))
		return soap->error;
	if (soap->mode & SOAP_IO_LENGTH)
	{	if (soap_envelope_begin_out(soap)
		 || soap_putheader(soap)
		 || soap_body_begin_out(soap)
		 || soap_put___ns1__applyEquip(soap, &soap_tmp___ns1__applyEquip, "-ns1:applyEquip", NULL)
		 || soap_body_end_out(soap)
		 || soap_envelope_end_out(soap))
			 return soap->error;
	}
	if (soap_end_count(soap))
		return soap->error;
	if (soap_connect(soap, soap_url(soap, soap_endpoint, NULL), soap_action)
	 || soap_envelope_begin_out(soap)
	 || soap_putheader(soap)
	 || soap_body_begin_out(soap)
	 || soap_put___ns1__applyEquip(soap, &soap_tmp___ns1__applyEquip, "-ns1:applyEquip", NULL)
	 || soap_body_end_out(soap)
	 || soap_envelope_end_out(soap)
	 || soap_end_send(soap))
		return soap_closesock(soap);
	if (!&ns1__applyEquipResponse)
		return soap_closesock(soap);
	ns1__applyEquipResponse.soap_default(soap);
	if (soap_begin_recv(soap)
	 || soap_envelope_begin_in(soap)
	 || soap_recv_header(soap)
	 || soap_body_begin_in(soap))
		return soap_closesock(soap);
	ns1__applyEquipResponse.soap_get(soap, "ns1:applyEquipResponse", NULL);
	if (soap->error)
		return soap_recv_fault(soap, 0);
	if (soap_body_end_in(soap)
	 || soap_envelope_end_in(soap)
	 || soap_end_recv(soap))
		return soap_closesock(soap);
	return soap_closesock(soap);
}

int DetectServiceHttpBindingProxy::getDBConnInfo(const char *endpoint, const char *soap_action, _ns1__getDBConnInfo *ns1__getDBConnInfo, _ns1__getDBConnInfoResponse &ns1__getDBConnInfoResponse)
{	struct soap *soap = this;
	struct __ns1__getDBConnInfo soap_tmp___ns1__getDBConnInfo;
	if (endpoint)
		soap_endpoint = endpoint;
	if (soap_endpoint == NULL)
		soap_endpoint = "http://10.158.249.98:7012/InterfaceWS/InterfaceBusiness/services/DetectService";
	if (soap_action == NULL)
		soap_action = "";
	soap_begin(soap);
	soap->encodingStyle = NULL;
	soap_tmp___ns1__getDBConnInfo.ns1__getDBConnInfo = ns1__getDBConnInfo;
	soap_serializeheader(soap);
	soap_serialize___ns1__getDBConnInfo(soap, &soap_tmp___ns1__getDBConnInfo);
	if (soap_begin_count(soap))
		return soap->error;
	if (soap->mode & SOAP_IO_LENGTH)
	{	if (soap_envelope_begin_out(soap)
		 || soap_putheader(soap)
		 || soap_body_begin_out(soap)
		 || soap_put___ns1__getDBConnInfo(soap, &soap_tmp___ns1__getDBConnInfo, "-ns1:getDBConnInfo", NULL)
		 || soap_body_end_out(soap)
		 || soap_envelope_end_out(soap))
			 return soap->error;
	}
	if (soap_end_count(soap))
		return soap->error;
	if (soap_connect(soap, soap_url(soap, soap_endpoint, NULL), soap_action)
	 || soap_envelope_begin_out(soap)
	 || soap_putheader(soap)
	 || soap_body_begin_out(soap)
	 || soap_put___ns1__getDBConnInfo(soap, &soap_tmp___ns1__getDBConnInfo, "-ns1:getDBConnInfo", NULL)
	 || soap_body_end_out(soap)
	 || soap_envelope_end_out(soap)
	 || soap_end_send(soap))
		return soap_closesock(soap);
	if (!&ns1__getDBConnInfoResponse)
		return soap_closesock(soap);
	ns1__getDBConnInfoResponse.soap_default(soap);
	if (soap_begin_recv(soap)
	 || soap_envelope_begin_in(soap)
	 || soap_recv_header(soap)
	 || soap_body_begin_in(soap))
		return soap_closesock(soap);
	ns1__getDBConnInfoResponse.soap_get(soap, "ns1:getDBConnInfoResponse", NULL);
	if (soap->error)
		return soap_recv_fault(soap, 0);
	if (soap_body_end_in(soap)
	 || soap_envelope_end_in(soap)
	 || soap_end_recv(soap))
		return soap_closesock(soap);
	return soap_closesock(soap);
}

int DetectServiceHttpBindingProxy::equipCheckInfo(const char *endpoint, const char *soap_action, _ns1__equipCheckInfo *ns1__equipCheckInfo, _ns1__equipCheckInfoResponse &ns1__equipCheckInfoResponse)
{	struct soap *soap = this;
	struct __ns1__equipCheckInfo soap_tmp___ns1__equipCheckInfo;
	if (endpoint)
		soap_endpoint = endpoint;
	if (soap_endpoint == NULL)
		soap_endpoint = "http://10.158.249.98:7012/InterfaceWS/InterfaceBusiness/services/DetectService";
	if (soap_action == NULL)
		soap_action = "";
	soap_begin(soap);
	soap->encodingStyle = NULL;
	soap_tmp___ns1__equipCheckInfo.ns1__equipCheckInfo = ns1__equipCheckInfo;
	soap_serializeheader(soap);
	soap_serialize___ns1__equipCheckInfo(soap, &soap_tmp___ns1__equipCheckInfo);
	if (soap_begin_count(soap))
		return soap->error;
	if (soap->mode & SOAP_IO_LENGTH)
	{	if (soap_envelope_begin_out(soap)
		 || soap_putheader(soap)
		 || soap_body_begin_out(soap)
		 || soap_put___ns1__equipCheckInfo(soap, &soap_tmp___ns1__equipCheckInfo, "-ns1:equipCheckInfo", NULL)
		 || soap_body_end_out(soap)
		 || soap_envelope_end_out(soap))
			 return soap->error;
	}
	if (soap_end_count(soap))
		return soap->error;
	if (soap_connect(soap, soap_url(soap, soap_endpoint, NULL), soap_action)
	 || soap_envelope_begin_out(soap)
	 || soap_putheader(soap)
	 || soap_body_begin_out(soap)
	 || soap_put___ns1__equipCheckInfo(soap, &soap_tmp___ns1__equipCheckInfo, "-ns1:equipCheckInfo", NULL)
	 || soap_body_end_out(soap)
	 || soap_envelope_end_out(soap)
	 || soap_end_send(soap))
		return soap_closesock(soap);
	if (!&ns1__equipCheckInfoResponse)
		return soap_closesock(soap);
	ns1__equipCheckInfoResponse.soap_default(soap);
	if (soap_begin_recv(soap)
	 || soap_envelope_begin_in(soap)
	 || soap_recv_header(soap)
	 || soap_body_begin_in(soap))
		return soap_closesock(soap);
	ns1__equipCheckInfoResponse.soap_get(soap, "ns1:equipCheckInfoResponse", NULL);
	if (soap->error)
		return soap_recv_fault(soap, 0);
	if (soap_body_end_in(soap)
	 || soap_envelope_end_in(soap)
	 || soap_end_recv(soap))
		return soap_closesock(soap);
	return soap_closesock(soap);
}

int DetectServiceHttpBindingProxy::boxCheckInfo(const char *endpoint, const char *soap_action, _ns1__boxCheckInfo *ns1__boxCheckInfo, _ns1__boxCheckInfoResponse &ns1__boxCheckInfoResponse)
{	struct soap *soap = this;
	struct __ns1__boxCheckInfo soap_tmp___ns1__boxCheckInfo;
	if (endpoint)
		soap_endpoint = endpoint;
	if (soap_endpoint == NULL)
		soap_endpoint = "http://10.158.249.98:7012/InterfaceWS/InterfaceBusiness/services/DetectService";
	if (soap_action == NULL)
		soap_action = "";
	soap_begin(soap);
	soap->encodingStyle = NULL;
	soap_tmp___ns1__boxCheckInfo.ns1__boxCheckInfo = ns1__boxCheckInfo;
	soap_serializeheader(soap);
	soap_serialize___ns1__boxCheckInfo(soap, &soap_tmp___ns1__boxCheckInfo);
	if (soap_begin_count(soap))
		return soap->error;
	if (soap->mode & SOAP_IO_LENGTH)
	{	if (soap_envelope_begin_out(soap)
		 || soap_putheader(soap)
		 || soap_body_begin_out(soap)
		 || soap_put___ns1__boxCheckInfo(soap, &soap_tmp___ns1__boxCheckInfo, "-ns1:boxCheckInfo", NULL)
		 || soap_body_end_out(soap)
		 || soap_envelope_end_out(soap))
			 return soap->error;
	}
	if (soap_end_count(soap))
		return soap->error;
	if (soap_connect(soap, soap_url(soap, soap_endpoint, NULL), soap_action)
	 || soap_envelope_begin_out(soap)
	 || soap_putheader(soap)
	 || soap_body_begin_out(soap)
	 || soap_put___ns1__boxCheckInfo(soap, &soap_tmp___ns1__boxCheckInfo, "-ns1:boxCheckInfo", NULL)
	 || soap_body_end_out(soap)
	 || soap_envelope_end_out(soap)
	 || soap_end_send(soap))
		return soap_closesock(soap);
	if (!&ns1__boxCheckInfoResponse)
		return soap_closesock(soap);
	ns1__boxCheckInfoResponse.soap_default(soap);
	if (soap_begin_recv(soap)
	 || soap_envelope_begin_in(soap)
	 || soap_recv_header(soap)
	 || soap_body_begin_in(soap))
		return soap_closesock(soap);
	ns1__boxCheckInfoResponse.soap_get(soap, "ns1:boxCheckInfoResponse", NULL);
	if (soap->error)
		return soap_recv_fault(soap, 0);
	if (soap_body_end_in(soap)
	 || soap_envelope_end_in(soap)
	 || soap_end_recv(soap))
		return soap_closesock(soap);
	return soap_closesock(soap);
}

int DetectServiceHttpBindingProxy::upBoxInputPileDet(const char *endpoint, const char *soap_action, _ns1__upBoxInputPileDet *ns1__upBoxInputPileDet, _ns1__upBoxInputPileDetResponse &ns1__upBoxInputPileDetResponse)
{	struct soap *soap = this;
	struct __ns1__upBoxInputPileDet soap_tmp___ns1__upBoxInputPileDet;
	if (endpoint)
		soap_endpoint = endpoint;
	if (soap_endpoint == NULL)
		soap_endpoint = "http://10.158.249.98:7012/InterfaceWS/InterfaceBusiness/services/DetectService";
	if (soap_action == NULL)
		soap_action = "";
	soap_begin(soap);
	soap->encodingStyle = NULL;
	soap_tmp___ns1__upBoxInputPileDet.ns1__upBoxInputPileDet = ns1__upBoxInputPileDet;
	soap_serializeheader(soap);
	soap_serialize___ns1__upBoxInputPileDet(soap, &soap_tmp___ns1__upBoxInputPileDet);
	if (soap_begin_count(soap))
		return soap->error;
	if (soap->mode & SOAP_IO_LENGTH)
	{	if (soap_envelope_begin_out(soap)
		 || soap_putheader(soap)
		 || soap_body_begin_out(soap)
		 || soap_put___ns1__upBoxInputPileDet(soap, &soap_tmp___ns1__upBoxInputPileDet, "-ns1:upBoxInputPileDet", NULL)
		 || soap_body_end_out(soap)
		 || soap_envelope_end_out(soap))
			 return soap->error;
	}
	if (soap_end_count(soap))
		return soap->error;
	if (soap_connect(soap, soap_url(soap, soap_endpoint, NULL), soap_action)
	 || soap_envelope_begin_out(soap)
	 || soap_putheader(soap)
	 || soap_body_begin_out(soap)
	 || soap_put___ns1__upBoxInputPileDet(soap, &soap_tmp___ns1__upBoxInputPileDet, "-ns1:upBoxInputPileDet", NULL)
	 || soap_body_end_out(soap)
	 || soap_envelope_end_out(soap)
	 || soap_end_send(soap))
		return soap_closesock(soap);
	if (!&ns1__upBoxInputPileDetResponse)
		return soap_closesock(soap);
	ns1__upBoxInputPileDetResponse.soap_default(soap);
	if (soap_begin_recv(soap)
	 || soap_envelope_begin_in(soap)
	 || soap_recv_header(soap)
	 || soap_body_begin_in(soap))
		return soap_closesock(soap);
	ns1__upBoxInputPileDetResponse.soap_get(soap, "ns1:upBoxInputPileDetResponse", NULL);
	if (soap->error)
		return soap_recv_fault(soap, 0);
	if (soap_body_end_in(soap)
	 || soap_envelope_end_in(soap)
	 || soap_end_recv(soap))
		return soap_closesock(soap);
	return soap_closesock(soap);
}

int DetectServiceHttpBindingProxy::getAlarm(const char *endpoint, const char *soap_action, _ns1__getAlarm *ns1__getAlarm, _ns1__getAlarmResponse &ns1__getAlarmResponse)
{	struct soap *soap = this;
	struct __ns1__getAlarm soap_tmp___ns1__getAlarm;
	if (endpoint)
		soap_endpoint = endpoint;
	if (soap_endpoint == NULL)
		soap_endpoint = "http://10.158.249.98:7012/InterfaceWS/InterfaceBusiness/services/DetectService";
	if (soap_action == NULL)
		soap_action = "";
	soap_begin(soap);
	soap->encodingStyle = NULL;
	soap_tmp___ns1__getAlarm.ns1__getAlarm = ns1__getAlarm;
	soap_serializeheader(soap);
	soap_serialize___ns1__getAlarm(soap, &soap_tmp___ns1__getAlarm);
	if (soap_begin_count(soap))
		return soap->error;
	if (soap->mode & SOAP_IO_LENGTH)
	{	if (soap_envelope_begin_out(soap)
		 || soap_putheader(soap)
		 || soap_body_begin_out(soap)
		 || soap_put___ns1__getAlarm(soap, &soap_tmp___ns1__getAlarm, "-ns1:getAlarm", NULL)
		 || soap_body_end_out(soap)
		 || soap_envelope_end_out(soap))
			 return soap->error;
	}
	if (soap_end_count(soap))
		return soap->error;
	if (soap_connect(soap, soap_url(soap, soap_endpoint, NULL), soap_action)
	 || soap_envelope_begin_out(soap)
	 || soap_putheader(soap)
	 || soap_body_begin_out(soap)
	 || soap_put___ns1__getAlarm(soap, &soap_tmp___ns1__getAlarm, "-ns1:getAlarm", NULL)
	 || soap_body_end_out(soap)
	 || soap_envelope_end_out(soap)
	 || soap_end_send(soap))
		return soap_closesock(soap);
	if (!&ns1__getAlarmResponse)
		return soap_closesock(soap);
	ns1__getAlarmResponse.soap_default(soap);
	if (soap_begin_recv(soap)
	 || soap_envelope_begin_in(soap)
	 || soap_recv_header(soap)
	 || soap_body_begin_in(soap))
		return soap_closesock(soap);
	ns1__getAlarmResponse.soap_get(soap, "ns1:getAlarmResponse", NULL);
	if (soap->error)
		return soap_recv_fault(soap, 0);
	if (soap_body_end_in(soap)
	 || soap_envelope_end_in(soap)
	 || soap_end_recv(soap))
		return soap_closesock(soap);
	return soap_closesock(soap);
}

int DetectServiceHttpBindingProxy::uploadPackInfo(const char *endpoint, const char *soap_action, _ns1__uploadPackInfo *ns1__uploadPackInfo, _ns1__uploadPackInfoResponse &ns1__uploadPackInfoResponse)
{	struct soap *soap = this;
	struct __ns1__uploadPackInfo soap_tmp___ns1__uploadPackInfo;
	if (endpoint)
		soap_endpoint = endpoint;
	if (soap_endpoint == NULL)
		soap_endpoint = "http://10.158.249.98:7012/InterfaceWS/InterfaceBusiness/services/DetectService";
	if (soap_action == NULL)
		soap_action = "";
	soap_begin(soap);
	soap->encodingStyle = NULL;
	soap_tmp___ns1__uploadPackInfo.ns1__uploadPackInfo = ns1__uploadPackInfo;
	soap_serializeheader(soap);
	soap_serialize___ns1__uploadPackInfo(soap, &soap_tmp___ns1__uploadPackInfo);
	if (soap_begin_count(soap))
		return soap->error;
	if (soap->mode & SOAP_IO_LENGTH)
	{	if (soap_envelope_begin_out(soap)
		 || soap_putheader(soap)
		 || soap_body_begin_out(soap)
		 || soap_put___ns1__uploadPackInfo(soap, &soap_tmp___ns1__uploadPackInfo, "-ns1:uploadPackInfo", NULL)
		 || soap_body_end_out(soap)
		 || soap_envelope_end_out(soap))
			 return soap->error;
	}
	if (soap_end_count(soap))
		return soap->error;
	if (soap_connect(soap, soap_url(soap, soap_endpoint, NULL), soap_action)
	 || soap_envelope_begin_out(soap)
	 || soap_putheader(soap)
	 || soap_body_begin_out(soap)
	 || soap_put___ns1__uploadPackInfo(soap, &soap_tmp___ns1__uploadPackInfo, "-ns1:uploadPackInfo", NULL)
	 || soap_body_end_out(soap)
	 || soap_envelope_end_out(soap)
	 || soap_end_send(soap))
		return soap_closesock(soap);
	if (!&ns1__uploadPackInfoResponse)
		return soap_closesock(soap);
	ns1__uploadPackInfoResponse.soap_default(soap);
	if (soap_begin_recv(soap)
	 || soap_envelope_begin_in(soap)
	 || soap_recv_header(soap)
	 || soap_body_begin_in(soap))
		return soap_closesock(soap);
	ns1__uploadPackInfoResponse.soap_get(soap, "ns1:uploadPackInfoResponse", NULL);
	if (soap->error)
		return soap_recv_fault(soap, 0);
	if (soap_body_end_in(soap)
	 || soap_envelope_end_in(soap)
	 || soap_end_recv(soap))
		return soap_closesock(soap);
	return soap_closesock(soap);
}
/* End of client proxy code */
