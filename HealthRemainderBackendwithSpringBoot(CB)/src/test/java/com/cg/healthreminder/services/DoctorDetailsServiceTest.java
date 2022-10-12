/**
 * @AnkitBanerjee
 * 
 * This is the Service Testing Class for Doctor Details.
*/
package com.cg.healthreminder.services;

import static org.assertj.core.api.Assertions.assertThat;

import org.junit.Test;
import org.junit.runner.RunWith;
import org.mockito.Mockito;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.boot.test.context.SpringBootTest;
import org.springframework.boot.test.mock.mockito.MockBean;
import org.springframework.test.context.junit4.SpringRunner;

import java.util.ArrayList;
import java.util.List;

import com.cg.healthreminder.dao.DoctorDetailsDao;
import com.cg.healthreminder.model.DoctorDetails;


@RunWith(SpringRunner.class)
@SpringBootTest
public class DoctorDetailsServiceTest {
	
	@MockBean
    private DoctorDetailsDao doctorDetailsDao;

    @Autowired
    private DoctorDetailsService doctorDetailsService;
	
    /**
	 * 
	 * To check if a new Doctor Details module gets created
	*/
    @Test
    public void testCreateDoctor(){
    	DoctorDetails doctorDetails = new DoctorDetails();
    	doctorDetails.setDoctorId(210);
    	doctorDetails.setDoctorName("Dr Ankit");
    	doctorDetails.setDoctorSpec("Dentist");
    	doctorDetails.setDoctorCertFile("Certified Doctor");
    	doctorDetails.setVerfStatus(true);
    	

        Mockito.when(doctorDetailsDao.save(doctorDetails)).thenReturn(doctorDetails);
        assertThat(doctorDetailsService.createDoctor(doctorDetails)).isEqualTo(doctorDetails);
    }
    
//    @Test
//    public void testGetDoctorById() throws Exception{
//    	DoctorDetails doctorDetails = new DoctorDetails();
//    	doctorDetails.setDoctorId(210);
//    	doctorDetails.setDoctorName("Dr. Kusum");
//    	doctorDetails.setDoctorSpec("Surgeon");
//    	doctorDetails.setDoctorCertFile("True");
//    	doctorDetails.setVerfStatus(true);
//    	
//    	DoctorDetails d2 = doctorDetailsDao.findById(210).get();
//        Mockito.when(d2).thenReturn(doctorDetails);
//        assertThat(doctorDetailsService.findDoctorById(null)).isEqualTo(doctorDetails);
//    }
    
    /**
	 * 
	 * To check if we able to find Doctor Details using Doctor specialization
	*/
    @Test
    public void testFindByDoctorSpec() throws Exception{
    	DoctorDetails doctorDetails = new DoctorDetails();
    	doctorDetails.setDoctorId(210);
    	doctorDetails.setDoctorName("Dr Ankit");
    	doctorDetails.setDoctorSpec("Dentist");
    	doctorDetails.setDoctorCertFile("Surgeon");
    	doctorDetails.setVerfStatus(true);
	  
	  Mockito.when(doctorDetailsDao.findDoctorBySpec("Surgeon")).thenReturn(doctorDetails);
      assertThat(doctorDetailsService.findDoctorBySpec("Surgeon")).isEqualTo(doctorDetails);
    }
    
    /**
	 * 
	 * To check if we able to get All Doctor Details 
	*/
    @Test
    public void testGetAllDoctors() throws Exception{
    	DoctorDetails d1 = new DoctorDetails();
    	d1.setDoctorId(210);
    	d1.setDoctorName("Dr Ankit");
    	d1.setDoctorSpec("Dentist");
    	d1.setDoctorCertFile("Certified Doctor");
    	d1.setVerfStatus(true);

    	DoctorDetails d2 = new DoctorDetails();
    	d2.setDoctorId(212);
    	d2.setDoctorName("Dr kusum");
    	d2.setDoctorSpec("Dentist");
    	d2.setDoctorCertFile("Certified Doctor");
    	d2.setVerfStatus(true);
        
        List<DoctorDetails> doctorList = new ArrayList<>();
        doctorList.add(d1);
        doctorList.add(d2);

        Mockito.when(doctorDetailsDao.findAll()).thenReturn(doctorList);
        assertThat(doctorDetailsService.getAllDoctorDetails()).isEqualTo(doctorList);
    
    }
    
//    @Test
//    public void testDeleteDoctorById() throws Exception{
//    	DoctorDetails doctorDetails = new DoctorDetails();
//    	doctorDetails.setDoctorId(210);
//    	doctorDetails.setDoctorName("Dr. Kusum");
//    	doctorDetails.setDoctorSpec("Surgeon");
//    	doctorDetails.setDoctorCertFile("True");
//    	doctorDetails.setVerfStatus(true);
//        
//        Mockito.when(doctorDetailsDao.save(doctorDetails)).thenReturn(doctorDetails);
//        Mockito.when(doctorDetailsDao.findById(210).get()).thenReturn(doctorDetails);
//        doctorDetailsDao.deleteById(doctorDetails.getDoctorId());
//        Mockito.when(doctorDetailsDao.findById(210).get()).thenReturn(doctorDetails);
//        Assert.assertNotEquals(doctorDetails, new DoctorDetails());
//        Assert.assertEquals(doctorDetailsService.deleteDoctorById(210), false);
//    }
    
    
}
