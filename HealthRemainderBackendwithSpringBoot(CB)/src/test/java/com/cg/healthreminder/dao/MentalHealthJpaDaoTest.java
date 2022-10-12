package com.cg.healthreminder.dao;

import org.junit.Test;
import org.junit.runner.RunWith;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.boot.test.autoconfigure.orm.jpa.DataJpaTest;
import org.springframework.boot.test.autoconfigure.orm.jpa.TestEntityManager;
import org.springframework.test.context.junit4.SpringRunner;



import static org.assertj.core.api.Assertions.assertThat;
import com.cg.healthreminder.model.MentalHealth;

/**
 * @ShaniaDalal
 * 
 * This is the Test Class for MentalHealth DAO
 */

@RunWith(SpringRunner.class)
@DataJpaTest
public class MentalHealthJpaDaoTest {
	 @Autowired
     private TestEntityManager testEntityManager;
	 @Autowired
     private MentalHealthJpaDao mentalJpaDao;
	 
	 /**
	  * Adding a test record
	  */
	 private MentalHealth getTips() {
		 MentalHealth m=new MentalHealth();
		 m.setMentalRating(5);
		 m.setMentalTip("You need to eat chocolate");
		 return m;
	 }

	 /**
	  * To test create a Tip
	  * and test all return statements
	  */
	 @Test
	 public void testNewTips() throws Exception{
	     MentalHealth mLocal = getTips();
	     MentalHealth saveInDb = testEntityManager.persist(mLocal);
	     MentalHealth getFromInDb = mentalJpaDao.findById(saveInDb.getMentalRating()).get();
	     assertThat(getFromInDb).isEqualTo(saveInDb);
	     assertThat(getFromInDb.toString()).hasToString(saveInDb.toString());
	     assertThat(getFromInDb.getMentalTip()).hasToString(saveInDb.getMentalTip());
	 }
	 


} 
