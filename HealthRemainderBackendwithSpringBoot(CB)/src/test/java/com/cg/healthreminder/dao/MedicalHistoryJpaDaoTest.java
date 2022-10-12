package com.cg.healthreminder.dao;
// Author: Naman Bhandari

import org.junit.Assert;
import org.junit.Test;
import org.junit.runner.RunWith;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.boot.test.autoconfigure.orm.jpa.DataJpaTest;
import org.springframework.boot.test.autoconfigure.orm.jpa.TestEntityManager;
import org.springframework.test.context.junit4.SpringRunner;

import com.cg.healthreminder.model.MedicalHistory;

import static org.assertj.core.api.Assertions.assertThat;

import java.util.List;

@RunWith(SpringRunner.class)
@DataJpaTest
public class MedicalHistoryJpaDaoTest {
	@Autowired
    private TestEntityManager testEntityManager;
	@Autowired
	private MedicalHistoryDao medicalHistoryDao;
	
	private MedicalHistory getMedicalHistory() {
		MedicalHistory mh = new MedicalHistory();
		mh.setFile("sample file");
		mh.setNotes("some notes");
		mh.setPatientId(1);
		return mh;
	}
	@Test
	public void testNewMedicalHistory() {
		MedicalHistory mh = getMedicalHistory();
		MedicalHistory saveInDb = testEntityManager.persist(mh);
		MedicalHistory getFromDb = medicalHistoryDao.findById(saveInDb.getFile()).get();
		assertThat(getFromDb).isEqualTo(saveInDb);
		assertThat(getFromDb.toString()).hasToString(saveInDb.toString());
		assertThat(getFromDb.getFile()).isEqualTo(saveInDb.getFile());
		assertThat(getFromDb.getNotes()).isEqualTo(saveInDb.getNotes());
		assertThat(getFromDb.getPatientId()).isEqualTo(saveInDb.getPatientId());

	}
	@Test
	public void testUpdateRecord() {
		MedicalHistory mh = getMedicalHistory();
		testEntityManager.persist(mh);
		MedicalHistory getFromDb = medicalHistoryDao.findById("sample file").get();
		getFromDb.setNotes("trial notes");
		assertThat(getFromDb.getNotes()).isEqualTo("trial notes");
	}
	@Test
	public void testDeleteRecord() {
		MedicalHistory m1 = getMedicalHistory();
		MedicalHistory m2 = new MedicalHistory();
		m2.setFile("file");
		m2.setNotes("notes");
		m2.setPatientId(1);
		testEntityManager.persist(m1);
		testEntityManager.persist(m2);
		testEntityManager.remove(m1);
		List<MedicalHistory> mhlst = medicalHistoryDao.findAll();
		Assert.assertEquals( 1,mhlst.size());
}
}