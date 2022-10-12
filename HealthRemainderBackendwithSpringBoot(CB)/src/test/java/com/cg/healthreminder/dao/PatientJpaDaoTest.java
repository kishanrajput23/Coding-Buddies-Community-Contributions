package com.cg.healthreminder.dao;

// Author: Naman Bhandari

import org.junit.Assert;
import org.junit.Test;
import org.junit.runner.RunWith;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.boot.test.autoconfigure.orm.jpa.DataJpaTest;
import org.springframework.boot.test.autoconfigure.orm.jpa.TestEntityManager;
import org.springframework.test.context.junit4.SpringRunner;

import com.cg.healthreminder.model.Patient;

import static org.assertj.core.api.Assertions.assertThat;

import java.util.List;

@RunWith(SpringRunner.class)
@DataJpaTest
public class PatientJpaDaoTest {
	@Autowired
    private TestEntityManager testEntityManager;
	@Autowired
	private PatientDao patientDao;
	
	private Patient getPatient() {
		Patient pt = new Patient();
		pt.setPatientId(100);
		pt.setPatientEmail("trial@trial.com");
		pt.setPatientMobile("1234567890");
		pt.setPatientName("qwerty");
		pt.setPatientAge(1);
		pt.setPatientHeight(1.0);
		pt.setPatientWeight(1.0);
		return pt;
	}
	
	@Test
	public void testNewPatient() throws Exception{
		Patient p = getPatient();
		Patient saveInDb = testEntityManager.persist(p);
		Patient getFromInDb = patientDao.findById(saveInDb.getPatientId()).get();
		assertThat(getFromInDb).isEqualTo(saveInDb);
		assertThat(getFromInDb.toString()).hasToString(saveInDb.toString());
		assertThat(getFromInDb.getPatientId()).isEqualTo(saveInDb.getPatientId());
		assertThat(getFromInDb.getPatientAge()).isEqualTo(saveInDb.getPatientAge());
		assertThat(getFromInDb.getPatientEmail()).isEqualTo(saveInDb.getPatientEmail());
		assertThat(getFromInDb.getPatientHeight()).isEqualTo(saveInDb.getPatientHeight());
		assertThat(getFromInDb.getPatientWeight()).isEqualTo(saveInDb.getPatientWeight());
		assertThat(getFromInDb.getPatientName()).isEqualTo(saveInDb.getPatientName());
		assertThat(getFromInDb.getPatientMobile()).isEqualTo(saveInDb.getPatientMobile());
	}
	
	@Test
	public void testGetPatientById() {
		Patient pt = new Patient();
		pt.setPatientId(100);
		pt.setPatientEmail("trial@trial.com");
		pt.setPatientMobile("1234567890");
		pt.setPatientName("qwerty");
		pt.setPatientAge(1);
		pt.setPatientHeight(1.0);
		pt.setPatientWeight(1.0);
		Patient saveInDb = testEntityManager.persist(pt);
		Patient getFromDb = patientDao.findById(pt.getPatientId()).get();
		assertThat(getFromDb).isEqualTo(saveInDb);
	}
	
	@Test
	public void testUpdatePatient() {
		Patient pt = new Patient();
		pt.setPatientId(100);
		pt.setPatientEmail("trial@trial.com");
		pt.setPatientMobile("1234567890");
		pt.setPatientName("qwerty");
		pt.setPatientAge(1);
		pt.setPatientHeight(1.0);
		pt.setPatientWeight(1.0);
		testEntityManager.persist(pt);
		Patient getFromDb = patientDao.findById(100).get();
		getFromDb.setPatientWeight(2.0);
		assertThat(getFromDb.getPatientWeight()).isEqualTo(2.0);
	}
	
	@Test
	public void testDeletePatient() {
		Patient p = getPatient();
		Patient pt = new Patient();
		pt.setPatientId(200);
		pt.setPatientEmail("trial@trial.com");
		pt.setPatientMobile("1234567890");
		pt.setPatientName("qwerty");
		pt.setPatientAge(1);
		pt.setPatientHeight(1.0);
		pt.setPatientWeight(1.0);
		testEntityManager.persist(p);
		testEntityManager.persist(pt);
		testEntityManager.remove(pt);
		List<Patient> lst = patientDao.findAll();
		Assert.assertEquals(1,lst.size());
	}
}
