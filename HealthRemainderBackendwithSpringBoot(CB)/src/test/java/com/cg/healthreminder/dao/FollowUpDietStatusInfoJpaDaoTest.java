package com.cg.healthreminder.dao;

import org.junit.Assert;
import org.junit.Test;
import org.junit.runner.RunWith;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.boot.test.autoconfigure.orm.jpa.DataJpaTest;
import org.springframework.boot.test.autoconfigure.orm.jpa.TestEntityManager;
import org.springframework.test.context.junit4.SpringRunner;

import com.cg.healthreminder.model.FollowUpDietStatusInfo;

import java.util.List;

import static org.assertj.core.api.Assertions.assertThat;

/**
 * @ParthGoel
 *
 * This is the test class for Follow Up Diet Status Information Dao
 */

@RunWith(SpringRunner.class)
@DataJpaTest
public class FollowUpDietStatusInfoJpaDaoTest {

	@Autowired
    private FollowUpDietStatusInfoJpaDao followUpDietStatusInfoJpaDao ;

    @Autowired
    private TestEntityManager testEntityManager;

    private FollowUpDietStatusInfo getFollowUpDietStatusInfo() {
    	FollowUpDietStatusInfo followUpDietStatusInfo = new FollowUpDietStatusInfo();
    	followUpDietStatusInfo.setPatientId(1);
    	followUpDietStatusInfo.setDietStatus(true);
        return followUpDietStatusInfo;
    }
    
    /**
	 * To test create follow up diet status information details   
	 */
    @Test
    public void testNewFollowUpDiet() throws Exception{
    	FollowUpDietStatusInfo followUpDietStatusInfo = getFollowUpDietStatusInfo();
    	FollowUpDietStatusInfo saveInDb = testEntityManager.persist(followUpDietStatusInfo);
    	FollowUpDietStatusInfo getFromInDb = followUpDietStatusInfoJpaDao.findById(saveInDb.getPatientId()).get();
        assertThat(getFromInDb).isEqualTo(saveInDb);
        assertThat(getFromInDb.toString()).hasToString(saveInDb.toString());
    }
    
    /**
	 * To test get follow up diet status information details using id  
	 */
    @Test
    public void testGetFollowUpDietStatusById() throws Exception{
    	FollowUpDietStatusInfo followUpDietStatusInfo = new FollowUpDietStatusInfo();
    	followUpDietStatusInfo.setPatientId(2);
    	followUpDietStatusInfo.setDietStatus(true);
       
    	FollowUpDietStatusInfo saveInDb = testEntityManager.persist(followUpDietStatusInfo);
        
    	FollowUpDietStatusInfo getInDb = followUpDietStatusInfoJpaDao.findById(followUpDietStatusInfo.getPatientId()).get();
        assertThat(getInDb).isEqualTo(saveInDb);
    }
    
    /**
	 * To test delete follow up diet status information details using id  
	 */
    @Test
    public void testDeleteFollowUpDietStatusInfoById() throws Exception{
    	FollowUpDietStatusInfo followUpDietStatusInfo1 = new FollowUpDietStatusInfo();
    	followUpDietStatusInfo1.setPatientId(2);
    	followUpDietStatusInfo1.setDietStatus(true);
        
        FollowUpDietStatusInfo followUpDietStatusInfo2 = new FollowUpDietStatusInfo();
        followUpDietStatusInfo2.setPatientId(3);
        followUpDietStatusInfo2.setDietStatus(true);

        FollowUpDietStatusInfo followUpDietStatusInfo = testEntityManager.persist(followUpDietStatusInfo1);
        testEntityManager.persist(followUpDietStatusInfo2);

        //delete one ticket DB
        testEntityManager.remove(followUpDietStatusInfo);

        List<FollowUpDietStatusInfo> followUpDietStatusInfos = (List<FollowUpDietStatusInfo>) followUpDietStatusInfoJpaDao.findAll();
        Assert.assertEquals(1, followUpDietStatusInfos.size());

    }
    
    /**
	 * To test update follow up diet status information details using id  
	 */
    @Test
    public void testUpdateFollowUpDietStatusInfo(){

    	FollowUpDietStatusInfo followUpDietStatusInfo = new FollowUpDietStatusInfo();
    	followUpDietStatusInfo.setPatientId(3);
    	followUpDietStatusInfo.setDietStatus(false);
        
        testEntityManager.persist(followUpDietStatusInfo);

        FollowUpDietStatusInfo getFromDb = followUpDietStatusInfoJpaDao.findById(3).get();
        getFromDb.setDietStatus(true);
        testEntityManager.persist(getFromDb);

        assertThat(getFromDb.getDietStatus()).isTrue();
    }


    
    
}
