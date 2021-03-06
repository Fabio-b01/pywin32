// This file implements the IShellView Interface and Gateway for Python.
// Generated by makegw.py

#include "shell_pch.h"
#include "PyIOleWindow.h"
#include "PyIShellView.h"

// @doc - This file contains autoduck documentation
// ---------------------------------------------------
//
// Interface Implementation

PyIShellView::PyIShellView(IUnknown *pdisp) : PyIOleWindow(pdisp) { ob_type = &type; }

PyIShellView::~PyIShellView() {}

/* static */ IShellView *PyIShellView::GetI(PyObject *self) { return (IShellView *)PyIOleWindow::GetI(self); }

// @pymethod int|PyIShellView|TranslateAccelerator|Description of TranslateAccelerator.
PyObject *PyIShellView::TranslateAccelerator(PyObject *self, PyObject *args)
{
    IShellView *pISV = GetI(self);
    if (pISV == NULL)
        return NULL;
    MSG msg;
    PyObject *obpmsg;
    // @pyparm tuple|pmsg||Description for pmsg
    if (!PyArg_ParseTuple(args, "O:TranslateAccelerator", &obpmsg))
        return NULL;
    BOOL bPythonIsHappy = TRUE;
    if (bPythonIsHappy && !PyObject_AsMSG(obpmsg, &msg))
        bPythonIsHappy = FALSE;
    if (!bPythonIsHappy)
        return NULL;
    HRESULT hr;
    PY_INTERFACE_PRECALL;
    hr = pISV->TranslateAccelerator(&msg);
    PY_INTERFACE_POSTCALL;
    if (FAILED(hr))
        return PyCom_BuildPyException(hr, pISV, IID_IShellView);
    // @rdesc The result is the HRESULT from the underlying TranslateAccelerator call
    return PyLong_FromLong(hr);
}

// @pymethod |PyIShellView|EnableModeless|Description of EnableModeless.
PyObject *PyIShellView::EnableModeless(PyObject *self, PyObject *args)
{
    IShellView *pISV = GetI(self);
    if (pISV == NULL)
        return NULL;
    // @pyparm int|fEnable||Description for fEnable
    BOOL fEnable;
    if (!PyArg_ParseTuple(args, "i:EnableModeless", &fEnable))
        return NULL;
    HRESULT hr;
    PY_INTERFACE_PRECALL;
    hr = pISV->EnableModeless(fEnable);
    PY_INTERFACE_POSTCALL;
    if (FAILED(hr))
        return PyCom_BuildPyException(hr, pISV, IID_IShellView);
    Py_INCREF(Py_None);
    return Py_None;
}

// @pymethod |PyIShellView|UIActivate|Description of UIActivate.
PyObject *PyIShellView::UIActivate(PyObject *self, PyObject *args)
{
    IShellView *pISV = GetI(self);
    if (pISV == NULL)
        return NULL;
    // @pyparm int|uState||Description for uState
    UINT uState;
    if (!PyArg_ParseTuple(args, "i:UIActivate", &uState))
        return NULL;
    HRESULT hr;
    PY_INTERFACE_PRECALL;
    hr = pISV->UIActivate(uState);
    PY_INTERFACE_POSTCALL;
    if (FAILED(hr))
        return PyCom_BuildPyException(hr, pISV, IID_IShellView);
    Py_INCREF(Py_None);
    return Py_None;
}

// @pymethod |PyIShellView|Refresh|Description of Refresh.
PyObject *PyIShellView::Refresh(PyObject *self, PyObject *args)
{
    IShellView *pISV = GetI(self);
    if (pISV == NULL)
        return NULL;
    if (!PyArg_ParseTuple(args, ":Refresh"))
        return NULL;
    HRESULT hr;
    PY_INTERFACE_PRECALL;
    hr = pISV->Refresh();
    PY_INTERFACE_POSTCALL;
    if (FAILED(hr))
        return PyCom_BuildPyException(hr, pISV, IID_IShellView);
    Py_INCREF(Py_None);
    return Py_None;
}

// @pymethod int|PyIShellView|CreateViewWindow|Description of CreateViewWindow.
PyObject *PyIShellView::CreateViewWindow(PyObject *self, PyObject *args)
{
    IShellView *pISV = GetI(self);
    if (pISV == NULL)
        return NULL;
    // @pyparm <o PyIShellView>|psvPrevious||Description for psvPrevious
    FOLDERSETTINGS fs;
    PyObject *obpfs;
    // @pyparm (int, int)|pfs||Description for pfs
    // @pyparm <o PyIShellBrowser>|psb||Description for psb
    RECT rcView;
    PyObject *obprcView;
    // @pyparm (int, int, int, int)|prcView||Description for prcView
    PyObject *obpsvPrevious;
    PyObject *obpsb;
    IShellView *psvPrevious;
    IShellBrowser *psb;
    if (!PyArg_ParseTuple(args, "OOOO:CreateViewWindow", &obpsvPrevious, &obpfs, &obpsb, &obprcView))
        return NULL;
    BOOL bPythonIsHappy = TRUE;
    if (bPythonIsHappy && !PyCom_InterfaceFromPyInstanceOrObject(obpsvPrevious, IID_IShellView, (void **)&psvPrevious,
                                                                 TRUE /* bNoneOK */))
        bPythonIsHappy = FALSE;
    if (bPythonIsHappy && !PyObject_AsFOLDERSETTINGS(obpfs, &fs))
        bPythonIsHappy = FALSE;
    if (bPythonIsHappy &&
        !PyCom_InterfaceFromPyInstanceOrObject(obpsb, IID_IShellBrowser, (void **)&psb, TRUE /* bNoneOK */))
        bPythonIsHappy = FALSE;
    if (bPythonIsHappy && !PyObject_AsRECT(obprcView, &rcView))
        bPythonIsHappy = FALSE;
    if (!bPythonIsHappy)
        return NULL;
    HWND hWnd;
    HRESULT hr;
    PY_INTERFACE_PRECALL;
    hr = pISV->CreateViewWindow(psvPrevious, &fs, psb, &rcView, &hWnd);
    if (psvPrevious)
        psvPrevious->Release();
    if (psb)
        psb->Release();
    PY_INTERFACE_POSTCALL;
    if (FAILED(hr))
        return PyCom_BuildPyException(hr, pISV, IID_IShellView);
    // @rdesc The result is an integer handle to the new window.
    return PyWinLong_FromHANDLE(hWnd);
}

// @pymethod |PyIShellView|DestroyViewWindow|Description of DestroyViewWindow.
PyObject *PyIShellView::DestroyViewWindow(PyObject *self, PyObject *args)
{
    IShellView *pISV = GetI(self);
    if (pISV == NULL)
        return NULL;
    if (!PyArg_ParseTuple(args, ":DestroyViewWindow"))
        return NULL;
    HRESULT hr;
    PY_INTERFACE_PRECALL;
    hr = pISV->DestroyViewWindow();
    PY_INTERFACE_POSTCALL;
    if (FAILED(hr))
        return PyCom_BuildPyException(hr, pISV, IID_IShellView);
    Py_INCREF(Py_None);
    return Py_None;
}

// @pymethod <o PyFOLDERSETTINGS>|PyIShellView|GetCurrentInfo|Description of GetCurrentInfo.
PyObject *PyIShellView::GetCurrentInfo(PyObject *self, PyObject *args)
{
    IShellView *pISV = GetI(self);
    if (pISV == NULL)
        return NULL;
    FOLDERSETTINGS fs;
    if (!PyArg_ParseTuple(args, ":GetCurrentInfo"))
        return NULL;
    HRESULT hr;
    PY_INTERFACE_PRECALL;
    hr = pISV->GetCurrentInfo(&fs);
    PY_INTERFACE_POSTCALL;
    if (FAILED(hr))
        return PyCom_BuildPyException(hr, pISV, IID_IShellView);
    return PyObject_FromFOLDERSETTINGS(&fs);
}

/*
// @pymethod |PyIShellView|AddPropertySheetPages|Description of AddPropertySheetPages.
PyObject *PyIShellView::AddPropertySheetPages(PyObject *self, PyObject *args)
{
    IShellView *pISV = GetI(self);
    if ( pISV == NULL )
        return NULL;
    // @pyparm int|dwReserved||Description for dwReserved
// *** The input argument pfn of type "LPFNSVADDPROPSHEETPAGE" was not processed ***
//     Please check the conversion function is appropriate and exists!
    LPFNSVADDPROPSHEETPAGE pfn;
    PyObject *obpfn;
    // @pyparm <o PyLPFNSVADDPROPSHEETPAGE>|pfn||Description for pfn
    // @pyparm long|lparam||Description for lparam
    DWORD dwReserved;
    LPARAM lparam;
    if ( !PyArg_ParseTuple(args, "lOl:AddPropertySheetPages", &dwReserved, &obpfn, &lparam) )
        return NULL;
    BOOL bPythonIsHappy = TRUE;
    if (bPythonIsHappy && !PyObject_AsLPFNSVADDPROPSHEETPAGE( obpfn, &pfn )) bPythonIsHappy = FALSE;
    if (!bPythonIsHappy) return NULL;
    HRESULT hr;
    PY_INTERFACE_PRECALL;
    hr = pISV->AddPropertySheetPages( dwReserved, pfn, lparam );
    PyObject_FreeLPFNSVADDPROPSHEETPAGE(pfn);

    PY_INTERFACE_POSTCALL;

    if ( FAILED(hr) )
        return PyCom_BuildPyException(hr, pISV, IID_IShellView );
    Py_INCREF(Py_None);
    return Py_None;

}
*/
// @pymethod |PyIShellView|SaveViewState|Description of SaveViewState.
PyObject *PyIShellView::SaveViewState(PyObject *self, PyObject *args)
{
    IShellView *pISV = GetI(self);
    if (pISV == NULL)
        return NULL;
    if (!PyArg_ParseTuple(args, ":SaveViewState"))
        return NULL;
    HRESULT hr;
    PY_INTERFACE_PRECALL;
    hr = pISV->SaveViewState();
    PY_INTERFACE_POSTCALL;
    if (FAILED(hr))
        return PyCom_BuildPyException(hr, pISV, IID_IShellView);
    Py_INCREF(Py_None);
    return Py_None;
}

// @pymethod |PyIShellView|SelectItem|Description of SelectItem.
PyObject *PyIShellView::SelectItem(PyObject *self, PyObject *args)
{
    IShellView *pISV = GetI(self);
    if (pISV == NULL)
        return NULL;
    // @pyparm <o PyIDL>|pidlItem||Description for pidlItem
    // @pyparm int|uFlags||Description for uFlags
    PyObject *obpidlItem;
    INT iuFlags;
    LPITEMIDLIST pidlItem;
    SVSIF uFlags;
    if (!PyArg_ParseTuple(args, "Oi:SelectItem", &obpidlItem, &iuFlags))
        return NULL;
    BOOL bPythonIsHappy = TRUE;
    if (bPythonIsHappy && !PyObject_AsPIDL(obpidlItem, &pidlItem, TRUE))
        bPythonIsHappy = FALSE;
    uFlags = iuFlags;
    if (!bPythonIsHappy)
        return NULL;
    HRESULT hr;
    PY_INTERFACE_PRECALL;
    hr = pISV->SelectItem(pidlItem, uFlags);
    PyObject_FreePIDL(pidlItem);
    PY_INTERFACE_POSTCALL;
    if (FAILED(hr))
        return PyCom_BuildPyException(hr, pISV, IID_IShellView);
    Py_INCREF(Py_None);
    return Py_None;
}

// @pymethod <o PyIUnknown>|PyIShellView|GetItemObject|Description of GetItemObject.
PyObject *PyIShellView::GetItemObject(PyObject *self, PyObject *args)
{
    IShellView *pISV = GetI(self);
    if (pISV == NULL)
        return NULL;
    // @pyparm int|uItem||Description for uItem
    // @pyparm <o PyIID>|riid||Description for riid
    PyObject *obriid;
    UINT uItem;
    IID riid;
    IUnknown *ppv;
    if (!PyArg_ParseTuple(args, "iO:GetItemObject", &uItem, &obriid))
        return NULL;
    BOOL bPythonIsHappy = TRUE;
    if (!PyWinObject_AsIID(obriid, &riid))
        bPythonIsHappy = FALSE;
    if (!bPythonIsHappy)
        return NULL;
    HRESULT hr;
    PY_INTERFACE_PRECALL;
    hr = pISV->GetItemObject(uItem, riid, (void **)&ppv);
    PY_INTERFACE_POSTCALL;
    if (FAILED(hr))
        return PyCom_BuildPyException(hr, pISV, IID_IShellView);
    return PyCom_PyObjectFromIUnknown(ppv, riid, FALSE);
}

// @object PyIShellView|Description of the interface
static struct PyMethodDef PyIShellView_methods[] = {
    {"TranslateAccelerator", PyIShellView::TranslateAccelerator,
     1},  // @pymeth TranslateAccelerator|Description of TranslateAccelerator
    {"EnableModeless", PyIShellView::EnableModeless, 1},  // @pymeth EnableModeless|Description of EnableModeless
    {"UIActivate", PyIShellView::UIActivate, 1},          // @pymeth UIActivate|Description of UIActivate
    {"Refresh", PyIShellView::Refresh, 1},                // @pymeth Refresh|Description of Refresh
    {"CreateViewWindow", PyIShellView::CreateViewWindow,
     1},  // @pymeth CreateViewWindow|Description of CreateViewWindow
    {"DestroyViewWindow", PyIShellView::DestroyViewWindow,
     1},                                                  // @pymeth DestroyViewWindow|Description of DestroyViewWindow
    {"GetCurrentInfo", PyIShellView::GetCurrentInfo, 1},  // @pymeth GetCurrentInfo|Description of GetCurrentInfo
    {"SaveViewState", PyIShellView::SaveViewState, 1},    // @pymeth SaveViewState|Description of SaveViewState
    {"SelectItem", PyIShellView::SelectItem, 1},          // @pymeth SelectItem|Description of SelectItem
    {"GetItemObject", PyIShellView::GetItemObject, 1},    // @pymeth GetItemObject|Description of GetItemObject
    {NULL}};

PyComTypeObject PyIShellView::type("PyIShellView", &PyIOleWindow::type, sizeof(PyIShellView), PyIShellView_methods,
                                   GET_PYCOM_CTOR(PyIShellView));
// ---------------------------------------------------
//
// Gateway Implementation
STDMETHODIMP PyGShellView::GetWindow(HWND __RPC_FAR *phwnd) { return PyGOleWindow::GetWindow(phwnd); }

STDMETHODIMP PyGShellView::ContextSensitiveHelp(BOOL fEnterMode)
{
    return PyGOleWindow::ContextSensitiveHelp(fEnterMode);
}

STDMETHODIMP PyGShellView::TranslateAccelerator(
    /* [in] */ MSG *pmsg)
{
    PY_GATEWAY_METHOD;
    PyObject *obpmsg = PyObject_FromMSG(pmsg);
    if (obpmsg == NULL)
        return MAKE_PYCOM_GATEWAY_FAILURE_CODE("TranslateAccelerator");
    PyObject *result;
    HRESULT hr = InvokeViaPolicy("TranslateAccelerator", &result, "(O)", obpmsg);
    Py_DECREF(obpmsg);
    if (FAILED(hr))
        return hr;
    // Process the Python results, and convert back to the real params
    if (PyLong_Check(result) || PyLong_Check(result))
        hr = PyLong_AsLong(result);
    Py_DECREF(result);
    return hr;
}

STDMETHODIMP PyGShellView::EnableModeless(
    /* [in] */ BOOL fEnable)
{
    PY_GATEWAY_METHOD;
    HRESULT hr = InvokeViaPolicy("EnableModeless", NULL, "i", fEnable);
    return hr;
}

STDMETHODIMP PyGShellView::UIActivate(
    /* [in] */ UINT uState)
{
    PY_GATEWAY_METHOD;
    HRESULT hr = InvokeViaPolicy("UIActivate", NULL, "i", uState);
    return hr;
}

STDMETHODIMP PyGShellView::Refresh(void)
{
    PY_GATEWAY_METHOD;
    HRESULT hr = InvokeViaPolicy("Refresh", NULL);
    return hr;
}

STDMETHODIMP PyGShellView::CreateViewWindow(
    /* [in] */ IShellView *psvPrevious,
    /* [in] */ LPCFOLDERSETTINGS pfs,
    /* [in] */ IShellBrowser *psb,
    /* [out] */ RECT *prcView,
    /* [out] */ HWND *phWnd)
{
    PY_GATEWAY_METHOD;
    PyObject *obpfs = PyObject_FromFOLDERSETTINGS(pfs);
    if (obpfs == NULL)
        return MAKE_PYCOM_GATEWAY_FAILURE_CODE("CreateViewWindow");
    PyObject *obrect = PyObject_FromRECT(prcView);
    if (obrect == NULL)
        return MAKE_PYCOM_GATEWAY_FAILURE_CODE("CreateViewWindow");
    PyObject *obpsvPrevious;
    PyObject *obpsb;
    obpsvPrevious = PyCom_PyObjectFromIUnknown(psvPrevious, IID_IShellView, TRUE);
    obpsb = PyCom_PyObjectFromIUnknown(psb, IID_IShellBrowser, TRUE);
    PyObject *result;
    HRESULT hr = InvokeViaPolicy("CreateViewWindow", &result, "OOOO", obpsvPrevious, obpfs, obpsb, obrect);
    Py_XDECREF(obpsvPrevious);
    Py_DECREF(obpfs);
    Py_XDECREF(obpsb);
    Py_DECREF(obrect);
    if (FAILED(hr))
        return hr;
    // Process the Python results, and convert back to the real params
    if (!PyWinObject_AsHANDLE(result, (HANDLE *)phWnd))
        hr = MAKE_PYCOM_GATEWAY_FAILURE_CODE("CreateViewWindow");
    Py_DECREF(result);
    return hr;
}

STDMETHODIMP PyGShellView::DestroyViewWindow(void)
{
    PY_GATEWAY_METHOD;
    HRESULT hr = InvokeViaPolicy("DestroyViewWindow", NULL);
    return hr;
}

STDMETHODIMP PyGShellView::GetCurrentInfo(
    /* [out] */ LPFOLDERSETTINGS pfs)
{
    PY_GATEWAY_METHOD;
    PyObject *result;
    HRESULT hr = InvokeViaPolicy("GetCurrentInfo", &result);
    if (FAILED(hr))
        return hr;
    // Process the Python results, and convert back to the real params
    PyObject_AsFOLDERSETTINGS(result, pfs);
    Py_DECREF(result);
    return MAKE_PYCOM_GATEWAY_FAILURE_CODE("GetCurrentInfo");
}

STDMETHODIMP PyGShellView::AddPropertySheetPages(
    /* [in] */ DWORD dwReserved,
    /* [in] */ LPFNSVADDPROPSHEETPAGE pfn,
    /* [in] */ LPARAM lparam)
{
    PY_GATEWAY_METHOD;
    // *** The input argument pfn of type "LPFNSVADDPROPSHEETPAGE" was not processed ***
    //   - Please ensure this conversion function exists, and is appropriate
    //   - The type 'LPFNSVADDPROPSHEETPAGE' (pfn) is unknown.
    PyObject *obpfn = Py_None;
    Py_INCREF(Py_None);
    if (obpfn == NULL)
        return MAKE_PYCOM_GATEWAY_FAILURE_CODE("AddPropertySheetPages");
    HRESULT hr =
        InvokeViaPolicy("AddPropertySheetPages", NULL, "lON", dwReserved, obpfn, PyWinObject_FromPARAM(lparam));
    Py_DECREF(obpfn);
    return hr;
}

STDMETHODIMP PyGShellView::SaveViewState(void)
{
    PY_GATEWAY_METHOD;
    HRESULT hr = InvokeViaPolicy("SaveViewState", NULL);
    return hr;
}

STDMETHODIMP PyGShellView::SelectItem(
    /* [in] */ LPCITEMIDLIST pidlItem,
    /* [in] */ SVSIF uFlags)
{
    PY_GATEWAY_METHOD;
    PyObject *obpidlItem;
    obpidlItem = PyObject_FromPIDL(pidlItem, FALSE);
    HRESULT hr = InvokeViaPolicy("SelectItem", NULL, "Oi", obpidlItem, uFlags);
    Py_XDECREF(obpidlItem);
    return hr;
}

STDMETHODIMP PyGShellView::GetItemObject(
    /* [in] */ UINT uItem,
    /* [in] */ REFIID riid,
    /* [iid_is][out] */ void **ppv)
{
    PY_GATEWAY_METHOD;
    *ppv = NULL;
    PyObject *obriid;
    obriid = PyWinObject_FromIID(riid);
    PyObject *result;
    HRESULT hr = InvokeViaPolicy("GetItemObject", &result, "iO", uItem, obriid);
    Py_XDECREF(obriid);
    if (FAILED(hr))
        return hr;
    // Process the Python results, and convert back to the real params
    PyObject *obppv;
    if (!PyArg_Parse(result, "O", &obppv))
        return MAKE_PYCOM_GATEWAY_FAILURE_CODE("GetItemObject");
    BOOL bPythonIsHappy = TRUE;
    if (bPythonIsHappy && !PyCom_InterfaceFromPyInstanceOrObject(obppv, riid, ppv, FALSE /* bNoneOK */))
        bPythonIsHappy = FALSE;
    if (!bPythonIsHappy)
        hr = MAKE_PYCOM_GATEWAY_FAILURE_CODE("GetItemObject");
    Py_DECREF(result);
    return hr;
}
