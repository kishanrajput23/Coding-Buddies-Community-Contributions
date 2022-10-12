package com.cg.healthreminder.services;

//@author Naman Bhandari

import org.junit.Test;
import org.junit.runner.RunWith;
import org.mockito.Mockito;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.boot.test.autoconfigure.web.servlet.AutoConfigureMockMvc;
import org.springframework.boot.test.context.SpringBootTest;
import org.springframework.boot.test.mock.mockito.MockBean;
import org.springframework.test.context.junit4.SpringRunner;

import com.cg.healthreminder.dao.PatientDao;
import com.cg.healthreminder.exception.AllCustomException;
import com.cg.healthreminder.model.Patient;

import java.util.ArrayList;
import java.util.List;

import static org.assertj.core.api.Assertions.assertThat;

@RunWith(SpringRunner.class)
@SpringBootTest
@AutoConfigureMockMvc
public class PatientServiceTest {
	@MockBean
    private PatientDao patientDao;

    @Autowired
    private PatientService patientService;
    
    @Test
    public void testCreatePatient() throws AllCustomException{
    	Patient pt = new Patient();
    	pt.setPatientId(100);
		pt.setPatientEmail("trial@trial.com");
		pt.setPatientMobile("1234567890");
		pt.setPatientName("qwerty");
		pt.setPatientAge(1);
		pt.setPatientHeight(1.0);
		pt.setPatientWeight(1.0);
		
		 Mockito.when(patientDao.save(pt)).thenReturn(pt);
	     assertThat(patientService.addPatient(pt)).isEqualTo(pt);
    }
    @Test
    public void testGetAllPatients() {
    	Patient pt = new Patient();
    	pt.setPatientId(100);
		pt.setPatientEmail("trial@trial.com");
		pt.setPatientMobile("1234567890");
		pt.setPatientName("qwerty");
		pt.setPatientAge(1);
		pt.setPatientHeight(1.0);
		pt.setPatientWeight(1.0);
		
		Patient pt1 = new Patient();
    	pt1.setPatientId(100);
		pt1.setPatientEmail("trial@trial.com");
		pt1.setPatientMobile("1234567890");
		pt1.setPatientName("qwerty");
		pt1.setPatientAge(1);
		pt1.setPatientHeight(1.0);
		pt1.setPatientWeight(1.0);
		
		List<Patient> ptlst = new ArrayList<>();
		ptlst.add(pt);
		ptlst.add(pt1);
		Mockito.when(patientDao.findAll()).thenReturn(ptlst);
        assertThat(patientService.getAllPatients()).isEqualTo(ptlst);
    }
    
    /*@Test
    public void testGetPatientById() throws Exception{
    	Patient pt = new Patient();
    	pt.setPatientId(100);
		pt.setPatientEmail("trial@trial.com");
		pt.setPatientMobile("1234567890");
		pt.setPatientName("qwerty");
		pt.setPatientAge(1);
		pt.setPatientHeight(1.0);
		pt.setPatientWeight(1.0);
		
		Mockito.when(patientDao.save(pt)).thenReturn(pt);
		assertThat(patientService.getPatient(100)).isEqualTo(pt);
    }*/
}
