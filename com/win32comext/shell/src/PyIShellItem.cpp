// This file implements the IShellItem Interface and Gateway for Python.
// Generated by makegw.py

#include "shell_pch.h"
#include "PyIShellItem.h"

// @doc - This file contains autoduck documentation
// ---------------------------------------------------
//
// Interface Implementation

PyIShellItem::PyIShellItem(IUnknown *pdisp) : PyIUnknown(pdisp) { ob_type = &type; }

PyIShellItem::~PyIShellItem() {}

/* static */ IShellItem *PyIShellItem::GetI(PyObject *self) { return (IShellItem *)PyIUnknown::GetI(self); }

// @pymethod interface|PyIShellItem|BindToHandler|Creates an instance of one of the item's handlers
PyObject *PyIShellItem::BindToHandler(PyObject *self, PyObject *args)
{
    IShellItem *pISI = GetI(self);
    if (pISI == NULL)
        return NULL;
    // @pyparm <o PyIBindCtx>|pbc||Used to pass parameters that influence the binding operation, can be None
    // @pyparm <o PyIID>|bhid||GUID that identifies a handler (shell.BHID_*)
    // @pyparm <o PyIID>|riid||The interface to return
    PyObject *obpbc;
    PyObject *obbhid;
    PyObject *obriid;
    IBindCtx *pbc;
    IID bhid;
    IID riid;
    void *pv;
    if (!PyArg_ParseTuple(args, "OOO:BindToHandler", &obpbc, &obbhid, &obriid))
        return NULL;
    if (!PyWinObject_AsIID(obbhid, &bhid))
        return NULL;
    if (!PyWinObject_AsIID(obriid, &riid))
        return NULL;
    if (!PyCom_InterfaceFromPyInstanceOrObject(obpbc, IID_IBindCtx, (void **)&pbc, TRUE /* bNoneOK */))
        return NULL;
    HRESULT hr;
    PY_INTERFACE_PRECALL;
    hr = pISI->BindToHandler(pbc, bhid, riid, &pv);
    if (pbc)
        pbc->Release();

    PY_INTERFACE_POSTCALL;

    if (FAILED(hr))
        return PyCom_BuildPyException(hr, pISI, IID_IShellItem);
    return PyCom_PyObjectFromIUnknown((IUnknown *)pv, riid, FALSE);
}

// @pymethod <o PyIShellItem>|PyIShellItem|GetParent|Retrieves the parent of this item
PyObject *PyIShellItem::GetParent(PyObject *self, PyObject *args)
{
    IShellItem *pISI = GetI(self);
    if (pISI == NULL)
        return NULL;
    IShellItem *psi;
    if (!PyArg_ParseTuple(args, ":GetParent"))
        return NULL;
    HRESULT hr;
    PY_INTERFACE_PRECALL;
    hr = pISI->GetParent(&psi);

    PY_INTERFACE_POSTCALL;

    if (FAILED(hr))
        return PyCom_BuildPyException(hr, pISI, IID_IShellItem);
    return PyCom_PyObjectFromIUnknown(psi, IID_IShellItem, FALSE);
}

// @pymethod str|PyIShellItem|GetDisplayName|Returns the display name of the item in the specified format
PyObject *PyIShellItem::GetDisplayName(PyObject *self, PyObject *args)
{
    IShellItem *pISI = GetI(self);
    if (pISI == NULL)
        return NULL;
    SIGDN sigdnName;
    // @pyparm int|sigdnName||Format of name to return, shellcon.SIGDN_*
    if (!PyArg_ParseTuple(args, "k:GetDisplayName", &sigdnName))
        return NULL;
    HRESULT hr;
    WCHAR *sz;
    PY_INTERFACE_PRECALL;
    hr = pISI->GetDisplayName(sigdnName, &sz);
    PY_INTERFACE_POSTCALL;

    if (FAILED(hr))
        return PyCom_BuildPyException(hr, pISI, IID_IShellItem);
    PyObject *ret = PyWinObject_FromWCHAR(sz);
    CoTaskMemFree(sz);
    return ret;
}

// @pymethod int|PyIShellItem|GetAttributes|Returns shell attributes of the item
// @rdesc Returns a combination of shellcon.SFGAO_* values
PyObject *PyIShellItem::GetAttributes(PyObject *self, PyObject *args)
{
    IShellItem *pISI = GetI(self);
    if (pISI == NULL)
        return NULL;
    SFGAOF sfgaoMask;
    SFGAOF ret;
    // @pyparm int|Mask||Combination of shellcon.SFGAO_* values indicating the flags to return
    if (!PyArg_ParseTuple(args, "k:GetAttributes", &sfgaoMask))
        return NULL;
    HRESULT hr;
    PY_INTERFACE_PRECALL;
    hr = pISI->GetAttributes(sfgaoMask, &ret);
    PY_INTERFACE_POSTCALL;

    if (FAILED(hr))
        return PyCom_BuildPyException(hr, pISI, IID_IShellItem);
    return PyLong_FromUnsignedLong(ret);
}

// @pymethod int|PyIShellItem|Compare|Compares another shell item with this item
// @rdesc Returns 0 if items compare as equal, nonzero otherwise
PyObject *PyIShellItem::Compare(PyObject *self, PyObject *args)
{
    IShellItem *pISI = GetI(self);
    if (pISI == NULL)
        return NULL;
    // @pyparm <o PyIShellItem>|psi||A shell item to be compared with this item
    SICHINTF hint;
    // @pyparm int|hint||shellcon.SICHINT_* value indicating how the comparison is to be performed
    PyObject *obpsi;
    IShellItem *psi;
    if (!PyArg_ParseTuple(args, "Oi:Compare", &obpsi, &hint))
        return NULL;
    if (!PyCom_InterfaceFromPyInstanceOrObject(obpsi, IID_IShellItem, (void **)&psi, FALSE))
        return NULL;
    HRESULT hr;
    int iOrder;
    PY_INTERFACE_PRECALL;
    hr = pISI->Compare(psi, hint, &iOrder);
    psi->Release();
    PY_INTERFACE_POSTCALL;

    if (FAILED(hr))
        return PyCom_BuildPyException(hr, pISI, IID_IShellItem);
    return PyLong_FromLong(iOrder);
}

// @object PyIShellItem|Interface that represents an item in the Explorer shell
static struct PyMethodDef PyIShellItem_methods[] = {
    {"BindToHandler", PyIShellItem::BindToHandler,
     1},  // @pymeth BindToHandler|Creates an instance of one of the item's handlers
    {"GetParent", PyIShellItem::GetParent, 1},  // @pymeth GetParent|Retrieves the parent of this item
    {"GetDisplayName", PyIShellItem::GetDisplayName,
     1},  // @pymeth GetDisplayName|Returns the display name of the item in the specified format
    {"GetAttributes", PyIShellItem::GetAttributes, 1},  // @pymeth GetAttributes|Returns shell attributes of the item
    {"Compare", PyIShellItem::Compare, 1},              // @pymeth Compare|Compares another shell item with this item
    {NULL}};

PyComTypeObject PyIShellItem::type("PyIShellItem", &PyIUnknown::type, sizeof(PyIShellItem), PyIShellItem_methods,
                                   GET_PYCOM_CTOR(PyIShellItem));
// ---------------------------------------------------
//
// Gateway Implementation
STDMETHODIMP PyGShellItem::BindToHandler(
    /* [unique][in] */ IBindCtx *pbc,
    /* [in] */ REFGUID bhid,
    /* [in] */ REFIID riid,
    /* [iid_is][out] */ void **ppv)
{
    PY_GATEWAY_METHOD;
    PyObject *obpbc;
    PyObject *obbhid;
    PyObject *obriid;
    obpbc = PyCom_PyObjectFromIUnknown(pbc, IID_IBindCtx, TRUE);
    obbhid = PyWinObject_FromIID(bhid);
    obriid = PyWinObject_FromIID(riid);
    PyObject *result;
    HRESULT hr = InvokeViaPolicy("BindToHandler", &result, "OOO", obpbc, obbhid, obriid);
    Py_XDECREF(obpbc);
    Py_XDECREF(obbhid);
    Py_XDECREF(obriid);
    if (FAILED(hr))
        return hr;
    // Process the Python results, and convert back to the real params
    PyObject *obppv;
    if (!PyArg_Parse(result, "O", &obppv))
        return MAKE_PYCOM_GATEWAY_FAILURE_CODE("BindToHandler");
    BOOL bPythonIsHappy = TRUE;
    if (bPythonIsHappy && !PyCom_InterfaceFromPyInstanceOrObject(obppv, riid, (void **)ppv, TRUE /* bNoneOK */))
        bPythonIsHappy = FALSE;
    if (!bPythonIsHappy)
        hr = MAKE_PYCOM_GATEWAY_FAILURE_CODE("BindToHandler");
    Py_DECREF(result);
    return hr;
}

STDMETHODIMP PyGShellItem::GetParent(
    /* [out] */ IShellItem **ppsi)
{
    PY_GATEWAY_METHOD;
    PyObject *result;
    HRESULT hr = InvokeViaPolicy("GetParent", &result);
    if (FAILED(hr))
        return hr;
    // Process the Python results, and convert back to the real params
    PyObject *obppsi;
    if (!PyArg_Parse(result, "O", &obppsi))
        return MAKE_PYCOM_GATEWAY_FAILURE_CODE("GetParent");
    BOOL bPythonIsHappy = TRUE;
    if (bPythonIsHappy &&
        !PyCom_InterfaceFromPyInstanceOrObject(obppsi, IID_IShellItem, (void **)ppsi, TRUE /* bNoneOK */))
        bPythonIsHappy = FALSE;
    if (!bPythonIsHappy)
        hr = MAKE_PYCOM_GATEWAY_FAILURE_CODE("GetParent");
    Py_DECREF(result);
    return hr;
}

STDMETHODIMP PyGShellItem::GetDisplayName(
    /* [in] */ SIGDN sigdnName,
    /* [string][out] */ LPWSTR *ppszName)
{
    PY_GATEWAY_METHOD;
    PyObject *result;
    HRESULT hr = InvokeViaPolicy("GetDisplayName", &result, "k", sigdnName);
    if (FAILED(hr))
        return hr;
    // Process the Python results, and convert back to the real params
    if (!PyWinObject_AsTaskAllocatedWCHAR(result, ppszName))
        hr = PyCom_SetAndLogCOMErrorFromPyException("GetDisplayName", IID_IShellItem);
    Py_DECREF(result);
    return hr;
}

STDMETHODIMP PyGShellItem::GetAttributes(
    /* [in] */ SFGAOF sfgaoMask,
    /* [out] */ SFGAOF *psfgaoAttribs)
{
    PY_GATEWAY_METHOD;
    PyObject *result;
    HRESULT hr = InvokeViaPolicy("GetAttributes", &result, "k", sfgaoMask);
    if (FAILED(hr))
        return hr;
    // Process the Python results, and convert back to the real params
    *psfgaoAttribs = PyLong_AsUnsignedLongMask(result);
    hr = PyCom_SetAndLogCOMErrorFromPyException("GetAttributes", IID_IShellItem);
    Py_DECREF(result);
    return hr;
}

STDMETHODIMP PyGShellItem::Compare(
    /* [in] */ IShellItem *psi,
    /* [in] */ SICHINTF hint,
    /* [out] */ int *piOrder)
{
    PY_GATEWAY_METHOD;
    PyObject *obpsi;
    obpsi = PyCom_PyObjectFromIUnknown(psi, IID_IShellItem, TRUE);
    PyObject *result;
    HRESULT hr = InvokeViaPolicy("Compare", &result, "Ok", obpsi, hint);
    Py_XDECREF(obpsi);
    if (FAILED(hr))
        return hr;
    *piOrder = PyLong_AsLong(result);
    hr = PyCom_SetAndLogCOMErrorFromPyException("Compare", IID_IShellItem);
    Py_DECREF(result);
    return hr;
}
