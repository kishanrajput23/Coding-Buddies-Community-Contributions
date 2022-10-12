package com.cg.healthreminder.dao;

import org.springframework.data.jpa.repository.JpaRepository;
import org.springframework.stereotype.Repository;

import com.cg.healthreminder.model.FollowUpDietStatusInfo;

/**
 * @ParthGoel
 *
 * This is the DAO class for Follow Up Diet status Information
 */

@Repository
public interface FollowUpDietStatusInfoJpaDao extends JpaRepository<FollowUpDietStatusInfo,Integer>{

}
