/**
 * @AnkitBanerjee
 * 
 * This is the DAO Repository Testing Class for Doctor Details.
*/
package com.cg.healthreminder.dao;
import static org.assertj.core.api.Assertions.assertThat;

import java.util.List;

import org.junit.Assert;
import org.junit.Test;
import org.junit.runner.RunWith;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.boot.test.autoconfigure.orm.jpa.DataJpaTest;
import org.springframework.boot.test.autoconfigure.orm.jpa.TestEntityManager;
import org.springframework.test.context.junit4.SpringRunner;

import com.cg.healthreminder.model.DoctorDetails;


@RunWith(SpringRunner.class)
@DataJpaTest
public class DoctorDetailsDaoTest {

	@Autowired
    private DoctorDetailsDao doctorDetailsDao;

    @Autowired
    private TestEntityManager testEntityManager;
    
    private DoctorDetails getDoctorDetails() {
    	
    	DoctorDetails d= new DoctorDetails();
    	d.setDoctorName("Dr Ankit");
        d.setDoctorSpec("Dentist");
        d.setDoctorCertFile("Certified Doctor");
    	d.setVerfStatus(true);
    	
		return d;
	}
    
    /**
	 * 
	 * Testing if new Doctor Details gets created.
	*/
    @Test
	public void testNewDoctorDetails() throws Exception{
    	DoctorDetails doctor = getDoctorDetails();
    	DoctorDetails saveInDb = testEntityManager.persist(doctor);
    	DoctorDetails getFromInDb = doctorDetailsDao.findDoctorById(saveInDb.getDoctorId());
		assertThat(getFromInDb).isEqualTo(saveInDb);
		assertThat(getFromInDb.toString()).hasToString(saveInDb.toString());
    }
    
    /**
	 * 
	 * Testing if Doctor Details can be found using doctor specialization.
	*/
    @Test
	public void testNewDoctorSpec() throws Exception{
    	DoctorDetails doctor = getDoctorDetails();
    	DoctorDetails saveInDb = testEntityManager.persist(doctor);
    	DoctorDetails getFromInDb = doctorDetailsDao.findDoctorBySpec(saveInDb.getDoctorSpec());
		assertThat(getFromInDb).isEqualTo(saveInDb);
	}
    
   
    /**
	 * 
	 * Testing the deletion of Doctor Details using doctor id.
	*/
    @Test
    public void testDeleteDoctorbyId() throws Exception{
    	
    	DoctorDetails d1 = new DoctorDetails();
    	d1.setDoctorName("Dr Ankit");
        d1.setDoctorSpec("Dentist");
        d1.setDoctorCertFile("Certified Doctor");
    	d1.setVerfStatus(true);
    	
    	DoctorDetails d2 = new DoctorDetails();
    	d2.setDoctorName("Dr Suman");
    	d2.setDoctorSpec("Child Spec");
    	d2.setDoctorCertFile("Certified Doctor");
    	d2.setVerfStatus(true);
    	
    	DoctorDetails doctodetails = testEntityManager.persist(d1);
    	testEntityManager.persist(d2);
    	
    	
    	//delete one ticket DB
    	testEntityManager.remove(doctodetails);
    	
    	List<DoctorDetails> alarmList = (List<DoctorDetails>) doctorDetailsDao.findAll();
    	Assert.assertEquals(1,alarmList.size());
    	
    	
    }
	
    
	
	
}
