package com.cg.healthreminder.services;

import com.cg.healthreminder.dao.FollowUpDietStatusInfoJpaDao;
import com.cg.healthreminder.model.FollowUpDietStatusInfo;
import org.junit.Test;
import org.junit.runner.RunWith;
import org.mockito.Mockito;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.boot.test.context.SpringBootTest;
import org.springframework.boot.test.mock.mockito.MockBean;
import org.springframework.test.context.junit4.SpringRunner;


import static org.assertj.core.api.Assertions.assertThat;

/**
 * @ParthGoel
 *
 * This is the test class for Follow Up Diet Status Information services
 */

@RunWith(SpringRunner.class)
@SpringBootTest
public class FollowUpDietStatusInfoServicesTest {

	@MockBean
    private FollowUpDietStatusInfoJpaDao followUpDietStatusInfoJpaDao;

    @Autowired
    private FollowUpDietStatusInfoServices followUpDietStatusInfoServices;
    
    /**
	 * To test create follow up diet status information details
	 */
    @Test
    public void testCreateDietStatus(){
        FollowUpDietStatusInfo followUpDietStatusInfo = new FollowUpDietStatusInfo();
        followUpDietStatusInfo.setPatientId(3);
        followUpDietStatusInfo.setDietStatus(true);
        followUpDietStatusInfo.setStreak(0);

        Mockito.when(followUpDietStatusInfoJpaDao.save(followUpDietStatusInfo)).thenReturn(followUpDietStatusInfo);
        assertThat(followUpDietStatusInfoServices.createDietStatus(followUpDietStatusInfo)).isEqualTo(followUpDietStatusInfo);
    }

}
