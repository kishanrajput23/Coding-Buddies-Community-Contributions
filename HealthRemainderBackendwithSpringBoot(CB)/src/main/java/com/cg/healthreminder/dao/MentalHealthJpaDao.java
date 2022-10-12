package com.cg.healthreminder.dao;

/**
 * @ShaniaDalal
 * 
 * This is the DAO class for MentalHealth model
 */

import org.springframework.data.jpa.repository.JpaRepository;
import org.springframework.stereotype.Repository;

import com.cg.healthreminder.model.MentalHealth;

@Repository
public interface MentalHealthJpaDao extends JpaRepository<MentalHealth,Integer>{

}

