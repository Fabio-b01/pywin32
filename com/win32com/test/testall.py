import win32ui
import sys, os
import pythoncom
from util import CheckClean

def GenerateAndRunOldStyle():
	import GenTestScripts
	GenTestScripts.GenerateAll()
	try:
		pass #
	finally:
		GenTestScripts.CleanAll()

def Prepare():
	import win32com, glob
	files = glob.glob(win32com.__gen_path__+"\\*")
	print "Deleting %d files from %s" % (len(files),win32com.__gen_path__)
	for f in files:
		os.unlink(f)
	import win32com.client.gencache
	win32com.client.gencache.__init__() # Reset
	
	
if __name__=='__main__':
	# default to "quick" test.  2==medium, 3==full
	testLevel = 1

	try:
		if len(sys.argv)>1:
			testLevel = int(sys.argv[1])
	except ValueError:
		print "Usage: testall [level], where level is 1, 2 or 3 (default 1, fulltest=3)"

	Prepare()

	import win32com.test.util
	capture = win32com.test.util.CaptureWriter()

	if testLevel>1:

		import testMSOffice
		testMSOffice.TestAll()

		capture.capture()
		try:	
			import testAccess
			testAccess.test()
			capture.release()
			print "MSAccess test generated %d lines of output" % capture.get_num_lines_captured()
		finally:
			capture.release()

		capture.capture()
		try:
			try:
				import testExchange
				testExchange.test()
			except ImportError:
				print "The Exchange Server tests can not be run..."
			capture.release()
			print "testExchange test generated %d lines of output" % capture.get_num_lines_captured()
		finally:
			capture.release()

		import testExplorer
		testExplorer.TestAll()


	capture.capture()
	try:
		import testStreams
		testStreams.test()
		capture.release()
		print "testStreams test generated %d lines of output" % capture.get_num_lines_captured()
	finally:
		capture.release()

#	try:
#		import testPyComTest
#		testPyComTest.TestAll()
#	except RuntimeError, why:
#		print why
	print "testPyComTest.py can not be tested from here..."

	import policySemantics
	policySemantics.TestAll()

	try:
		import testvb
		testvb.TestAll()
	except RuntimeError, why:
		print why


	import testAXScript
	testAXScript.RegisterEngine()
	testAXScript.TestAll()

	import testCollections
	testCollections.TestEnum(1)

	import testDictionary
	testDictionary.TestDict(1)

	import testServers
	testServers.TestAll()

	# Test VBScript and JScript which call back into Python
	rc = os.system("cscript testInterp.vbs")
	if rc:
		print "'cscript.exe testInterp.vbs' failed!!!"

	rc = os.system("cscript testPyScriptlet.js")
	if rc:
		# Note that this test assumes 'Testpys.sct' has been previously registered.
		# To register this test, simply run 'regsvr32.exe Testpys.sct'
		print "testPyScriptlet failed - has Scriptlets been installed and 'Testpys.sct' been registered?!!!"

	if testLevel>2:

		import testmakepy
		print "Running makepy over every registered typelib..."
		testmakepy.TestAll(0)

	print "Tests completed."
	CheckClean()
	pythoncom.CoUninitialize()

