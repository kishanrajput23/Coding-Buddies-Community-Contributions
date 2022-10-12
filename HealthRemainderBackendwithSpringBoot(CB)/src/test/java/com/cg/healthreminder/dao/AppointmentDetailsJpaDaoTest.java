/**
 * @SayantanDas
 * 
 * This is the DAORepository Testing Class for AppointmentDetails.
*/
package com.cg.healthreminder.dao;


import org.junit.Test;
import org.junit.runner.RunWith;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.boot.test.autoconfigure.orm.jpa.DataJpaTest;
import org.springframework.boot.test.autoconfigure.orm.jpa.TestEntityManager;
import org.springframework.test.context.junit4.SpringRunner;
import org.junit.Assert;



import static org.assertj.core.api.Assertions.assertThat;

import java.util.List;

import com.cg.healthreminder.model.AppointmentDetails;

@RunWith(SpringRunner.class)
@DataJpaTest
public class AppointmentDetailsJpaDaoTest {
	 @Autowired
     private TestEntityManager testEntityManager;
	 @Autowired
     private AppointmentDetailsJpaDao appointmentDetailsJpaDao;
	 
	 private AppointmentDetails getAppointmentDetails() {
		 AppointmentDetails a= new AppointmentDetails();
		  a.setDoctorId(5);
		  a.setDoctorName("DoctorAstin");
		  a.setDoctorStartTime("12:00");
		  a.setDoctorEndTime("9:00");
		  a.setDoctorDate("12/05/2020"); 
		  a.setPatientName("Sayantan");
		  a.setPatientId(4);

		 
		 return a;
	 }

	/**
	 * 
	 * To check if a new appointment gets created
	*/
	 @Test
	 public void testNewAppointmentDetails() throws Exception{
	     AppointmentDetails apd = getAppointmentDetails();
	     AppointmentDetails saveInDb = testEntityManager.persist(apd);
	     AppointmentDetails getFromInDb = appointmentDetailsJpaDao.findById(saveInDb.getAppId()).get();
	     assertThat(getFromInDb).isEqualTo(saveInDb);
	     assertThat(saveInDb.toString()).hasToString(getFromInDb.toString());
	 }
	 
	   
	 /**
	 * 
	 * Check if able to find Appointment by PatientId.
	*/
	 @Test
	 public void testGetAppointmentDetailsByPatientId() throws Exception{
		 AppointmentDetails apd = getAppointmentDetails();
		 AppointmentDetails saveInDb = testEntityManager.persist(apd);
	     AppointmentDetails getInDb = appointmentDetailsJpaDao.findByPatientId(apd.getPatientId());
	     assertThat(getInDb).isEqualTo(saveInDb);
	    }
	 
	 
	 /**
	 * 
	 * Check if able to find Appointment by DoctorId.
	*/
	 @Test
	 public void testGetAppointmentDetailsByDoctorId() throws Exception{
		 AppointmentDetails apd = getAppointmentDetails();
		 AppointmentDetails saveInDb = testEntityManager.persist(apd);
	     AppointmentDetails getInDb = appointmentDetailsJpaDao.findByDoctorId(apd.getDoctorId());
	     assertThat(getInDb).isEqualTo(saveInDb);
	    }
	 
	 
	/**
	 * 
	 * Check if able to delete Appointment.
	*/
	 @Test
	 public void testDeleteAppointment() throws Exception{
	       AppointmentDetails apd1 = getAppointmentDetails();
	       AppointmentDetails apd2= new AppointmentDetails();
	       apd2.setDoctorId(3);
		   apd2.setDoctorName("DoctorKaran");
		   apd2.setDoctorStartTime("12:00");
		   apd2.setDoctorEndTime("9:00");
		   apd2.setDoctorDate("12/16/2020"); 
		   apd2.setPatientName("Deepak");
		   apd2.setPatientId(7);

	        AppointmentDetails app = testEntityManager.persist(apd1);
	        testEntityManager.persist(apd2);

	        //delete one ticket DB
	        testEntityManager.remove(app);

	        List<AppointmentDetails> tickets = (List<AppointmentDetails>) appointmentDetailsJpaDao.findAll();
	        Assert.assertEquals(1,tickets.size());

	    }


}
