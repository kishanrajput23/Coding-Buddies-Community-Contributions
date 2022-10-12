package com.cg.healthreminder.dao;

import org.springframework.data.jpa.repository.JpaRepository;
import org.springframework.stereotype.Repository;

import com.cg.healthreminder.model.FollowUpMentalRatingInfo;

/**
 * @ParthGoel
 *
 * This is the DAO class for Follow Up Mental Rating Information
 */

@Repository
public interface FollowUpMentalRatingInfoJpaDao extends JpaRepository<FollowUpMentalRatingInfo,Integer>{

}
