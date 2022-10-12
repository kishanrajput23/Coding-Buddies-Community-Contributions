/**
 * @SayantanDas
 * 
 * This is the Service Testing Class for AppointmentDetails.
*/

package com.cg.healthreminder.services;

import org.junit.Test;
import org.junit.runner.RunWith;
import org.mockito.Mockito;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.boot.test.context.SpringBootTest;
import org.springframework.boot.test.mock.mockito.MockBean;
import org.springframework.test.context.junit4.SpringRunner;

import com.cg.healthreminder.dao.AppointmentDetailsJpaDao;
import com.cg.healthreminder.model.AppointmentDetails;



import static org.assertj.core.api.Assertions.assertThat;

@RunWith(SpringRunner.class)
@SpringBootTest
public class AppointmentDetailsServicesTest {
	  @MockBean
	  private AppointmentDetailsJpaDao appointmentDetailsJpaDao;

	  @Autowired
	  private AppointmentDetailsServices appointmentDetailServices;
	  
	  
	    /**
		 * 
		 * To check if a new appointment gets created
		*/	  
	  @Test
	    public void testCreateAppointment(){
		  AppointmentDetails a= new AppointmentDetails();
		  a.setAppId(1);
		  a.setDoctorId(5);
		  a.setDoctorName("Doctor Astin");
		  a.setDoctorStartTime("12:00");
		  a.setDoctorEndTime("9:00");
		  a.setDoctorDate("12/02/2020"); 
		  a.setPatientName("Sayantan");
		  a.setPatientId(4);

		  Mockito.when(appointmentDetailsJpaDao.save(a)).thenReturn(a);
          assertThat(appointmentDetailServices.createAppointment(a)).isEqualTo(a);
	    }
	  
	    /**
		 * 
		 * Check if able to find Appointment by PatientId.
		*/
	  @Test
	    public void testFindByPatientId() throws Exception{
		  AppointmentDetails a= new AppointmentDetails();
		  a.setAppId(1);
		  a.setDoctorId(5);
		  a.setDoctorName("Doctor Astin");
		  a.setDoctorStartTime("12:00");
		  a.setDoctorEndTime("9:00");
		  a.setDoctorDate("12/02/2020");
		  a.setPatientName("Sayantan");
		  a.setPatientId(4);
		  
		  Mockito.when(appointmentDetailsJpaDao.findByPatientId(4)).thenReturn(a);
	      assertThat(appointmentDetailServices.findAppointmentDetailByPatientId(4)).isEqualTo(a);
	    }
	  
	  
	    /**
		 * 
		 * Check if able to find Appointment by DoctorId.
		*/
	  @Test
	    public void testFindByDoctorId() throws Exception{
		  AppointmentDetails a= new AppointmentDetails();
		  a.setAppId(1);
		  a.setDoctorId(5);
		  a.setDoctorName("Doctor Astin");
		  a.setDoctorStartTime("12:00");
		  a.setDoctorEndTime("9:00");
		  a.setDoctorDate("12/02/2020"); 
		  a.setPatientName("Sayantan");
		  a.setPatientId(4);
		  
		  Mockito.when(appointmentDetailsJpaDao.findByDoctorId(5)).thenReturn(a);
	      assertThat(appointmentDetailServices.findAppointmentDetailByDoctorId(5)).isEqualTo(a);
	    }

	  
	    /**
		 * 
		 * Check if able to delete Appointment by PatientId.
		*/
	 /* @Test
	    public void testDeleteAppointmentByPatientId() throws Exception{
		  AppointmentDetails a= new AppointmentDetails();
		  a.setAppId(1);
		  a.setDoctorId(5);
		  a.setDoctorName("Doctor Astin");
		  a.setDoctorStartTime(Timestamp.valueOf("2020-05-01 15:30:00.0"));
		  a.setDoctorEndTime(Timestamp.valueOf("2020-05-01 15:30:00.0"));
		  a.setDoctorDate(Date.valueOf("2020-12-16")); 
		  a.setPatientName("Sayantan");
		  a.setPatientId(4);

		  
		  Mockito.when(appointmentDetailsJpaDao.save(any(AppointmentDetails.class))).thenReturn(a);
		  System.out.println(appointmentDetailsJpaDao.findByPatientId(4));
	      //Mockito.when(appointmentDetailsJpaDao.findByPatientId(4)).thenReturn(a);
	      //assertThat(appointmentDetailServices.findAppointmentDetailByPatientId(4)).isEqualTo(a);
	     // appointmentDetailsJpaDao.deleteById(a.getApp_id());
	      //Mockito.when(appointmentDetailsJpaDao.findById(1).get()).thenReturn(a);
		  
	      //assertThat(appointmentDetailServices.deleteAppointmentByPatientId(4)).isEqualTo(a);
		  System.out.println(appointmentDetailServices.deleteAppointmentByPatientId(4));
	    }*/
}
