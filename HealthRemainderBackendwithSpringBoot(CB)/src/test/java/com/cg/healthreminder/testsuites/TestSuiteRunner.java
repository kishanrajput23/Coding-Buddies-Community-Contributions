/**
 * @SayantanDas
 * 
 * This is the Class for running the test suite.
*/

package com.cg.healthreminder.testsuites;
import org.junit.runner.JUnitCore;
import org.junit.runner.Result;
import org.junit.runner.notification.Failure;

public class TestSuiteRunner {
	public static void main(String[] args) {
	      
		  Result result = JUnitCore.runClasses(TestSuiteCasesToRun.class);
	      for (Failure failure : result.getFailures()) {
	         System.out.println(failure.toString());
	      }
			
	      System.out.println(result.wasSuccessful()+" All test Suites Running");
	   }
}
