/**
 * @SayantanDas
 * 
 * This is the Testing SUite containing test cases.
*/

package com.cg.healthreminder.testsuites;
import org.junit.runner.RunWith;
import org.junit.runners.Suite;

import com.cg.healthreminder.controller.AlarmModuleControllerTest;
import com.cg.healthreminder.controller.AppointmentDetailsControllerTest;
import com.cg.healthreminder.controller.DietInfoControllerTest;
import com.cg.healthreminder.controller.DiseaseControllerTest;
import com.cg.healthreminder.controller.MedicalHistoryControllerTest;
import com.cg.healthreminder.services.AlarmModuleServiceTest;
import com.cg.healthreminder.services.AppointmentDetailsServicesTest;
import com.cg.healthreminder.services.DietInfoServicesTest;
import com.cg.healthreminder.services.DiseaseServicesTest;
import com.cg.healthreminder.services.MedicalHistoryServiceTest;

@RunWith(Suite.class)

@Suite.SuiteClasses({
	
   /** 	
    * @author Sayantan Das
    */
   AppointmentDetailsControllerTest.class,
   AppointmentDetailsServicesTest.class,
   
   /** 	
    * @author Naman Bhandari
    */
   MedicalHistoryControllerTest.class,
   MedicalHistoryServiceTest.class,
   
   /** 	
    * @author Parth Goel
    */
   DietInfoControllerTest.class,
   DietInfoServicesTest.class,   
   
   /** 	
    * @author Ankit
    */
   AlarmModuleControllerTest.class,
   AlarmModuleServiceTest.class,  
   
   /** 	
    * @author Shania
    */
   DiseaseControllerTest.class,
   DiseaseServicesTest.class
})
public class TestSuiteCasesToRun {

}
