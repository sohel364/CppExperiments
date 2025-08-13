// dllmain.h : Declaration of module class.

class CCOMModule : public ATL::CAtlDllModuleT< CCOMModule >
{
public :
	DECLARE_LIBID(LIBID_COMLib)
	DECLARE_REGISTRY_APPID_RESOURCEID(IDR_COM, "{e21185df-27da-4600-9da9-d87108dde45b}")
};

extern class CCOMModule _AtlModule;
