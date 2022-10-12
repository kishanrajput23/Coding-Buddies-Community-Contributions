package com.cg.healthreminder.services;

import com.cg.healthreminder.dao.FollowUpMentalRatingInfoJpaDao;
import com.cg.healthreminder.model.FollowUpMentalRatingInfo;
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
 * This is the test class for Follow Up Mental Rating Information services
 */

@RunWith(SpringRunner.class)
@SpringBootTest
public class FollowUpMentalRatingInfoServicesTest {

	@MockBean
    private FollowUpMentalRatingInfoJpaDao followUpMentalRatingInfoJpaDao;

    @Autowired
    private FollowUpMentalRatingInfoServices followUpMentalRatingInfoServices;
    
    /**
	 * To test create follow up mental rating information details
	 */
    @Test
    public void testCreateMentalRating(){
        FollowUpMentalRatingInfo followUpMentalRatingInfo = new FollowUpMentalRatingInfo();
        followUpMentalRatingInfo.setPatientId(3);
        followUpMentalRatingInfo.setMentalRating(5);

        Mockito.when(followUpMentalRatingInfoJpaDao.save(followUpMentalRatingInfo)).thenReturn(followUpMentalRatingInfo);
        assertThat(followUpMentalRatingInfoServices.createMentalRating(followUpMentalRatingInfo)).isEqualTo(followUpMentalRatingInfo);
    }

}
