// This file declares the ICreateTypeLib Interface for Python.
// Generated by makegw.py
// ---------------------------------------------------
//
// Interface Declaration

class PyICreateTypeLib : public PyIUnknown
{
public:
	MAKE_PYCOM_CTOR(PyICreateTypeLib);
	static ICreateTypeLib *GetI(PyObject *self);
	static PyComTypeObject type;

	// The Python methods
	static PyObject *CreateTypeInfo(PyObject *self, PyObject *args);
	static PyObject *SetName(PyObject *self, PyObject *args);
	static PyObject *SetVersion(PyObject *self, PyObject *args);
	static PyObject *SetGuid(PyObject *self, PyObject *args);
	static PyObject *SetDocString(PyObject *self, PyObject *args);
	static PyObject *SetHelpFileName(PyObject *self, PyObject *args);
	static PyObject *SetHelpContext(PyObject *self, PyObject *args);
	static PyObject *SetLcid(PyObject *self, PyObject *args);
	static PyObject *SetLibFlags(PyObject *self, PyObject *args);
	static PyObject *SaveAllChanges(PyObject *self, PyObject *args);

protected:
	PyICreateTypeLib(IUnknown *pdisp);
	~PyICreateTypeLib();
};
