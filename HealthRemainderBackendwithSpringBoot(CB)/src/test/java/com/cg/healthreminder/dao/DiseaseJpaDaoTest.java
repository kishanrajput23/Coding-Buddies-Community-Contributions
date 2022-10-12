package com.cg.healthreminder.dao;

import org.junit.Test;
import org.junit.runner.RunWith;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.boot.test.autoconfigure.orm.jpa.DataJpaTest;
import org.springframework.boot.test.autoconfigure.orm.jpa.TestEntityManager;
import org.springframework.test.context.junit4.SpringRunner;



import static org.assertj.core.api.Assertions.assertThat;

import com.cg.healthreminder.model.Diseases;

/**
 * @ShaniaDalal
 * 
 * This is the Test Class for Disease DAO
 */


@RunWith(SpringRunner.class)
@DataJpaTest
public class DiseaseJpaDaoTest {
	 @Autowired
     private TestEntityManager testEntityManager;
	 @Autowired
     private DiseaseJpaDao diseaseJpaDao;
	 
	 /**
	  * Adding a test record
	  */
	 private Diseases getDiseases() {
		 Diseases d=new Diseases();
		 d.setDiseaseId(5);
		 d.setDiseaseName("Cough");
		 d.setDiseaseInfo("Throat Irritation");
		 d.setDiseaseKeys("cough");
		 
		 return d;
	 }
	 
	 /**
	  * To test create a Disease
	  * and test all return statements
	  */
	 @Test
	 public void testNewDiseases() throws Exception{
	     Diseases dLocal = getDiseases();
	     //System.out.println(dLocal);
	     Diseases saveInDb = testEntityManager.merge(dLocal);
	     Diseases getFromInDb = diseaseJpaDao.findById(saveInDb.getDiseaseId()).get();
	     assertThat(getFromInDb).isEqualTo(saveInDb);
	     assertThat(getFromInDb.toString()).hasToString(saveInDb.toString());
	     assertThat(getFromInDb.getDiseaseName()).hasToString(saveInDb.getDiseaseName());
	     assertThat(getFromInDb.getDiseaseInfo()).hasToString(saveInDb.getDiseaseInfo());
	     assertThat(getFromInDb.getDiseaseKeys()).hasToString(saveInDb.getDiseaseKeys());
	 }
	 
/*	 @Test
	 public void testNewDiseases() throws Exception{
	     Diseases dLocal = getDiseases();
	     //System.out.println(dLocal);
	     Diseases saveInDb = testEntityManager.merge(dLocal);
	     Diseases getFromInDb = diseaseJpaDao.findById(saveInDb.getDiseaseId()).get();
	     assertThat(getFromInDb).isEqualTo(saveInDb);
	 }
	 */
} 
