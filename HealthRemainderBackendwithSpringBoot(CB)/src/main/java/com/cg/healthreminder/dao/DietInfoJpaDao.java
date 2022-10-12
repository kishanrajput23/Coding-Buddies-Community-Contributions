package com.cg.healthreminder.dao;

import org.springframework.data.jpa.repository.JpaRepository;
import org.springframework.stereotype.Repository;

import com.cg.healthreminder.model.DietInfo;

/**
 * @ParthGoel
 *
 * This is the DAO class for Diet Information
 */

@Repository
public interface DietInfoJpaDao extends JpaRepository<DietInfo,Integer>{

}
