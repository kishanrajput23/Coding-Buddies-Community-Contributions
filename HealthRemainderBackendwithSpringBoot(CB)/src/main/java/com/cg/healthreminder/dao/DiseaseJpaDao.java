package com.cg.healthreminder.dao;

/**
 * @ShaniaDalal
 * 
 * This is the DAO class for Diseases model
 */

import org.springframework.data.jpa.repository.JpaRepository;
import org.springframework.stereotype.Repository;
import com.cg.healthreminder.model.Diseases;

@Repository
public interface DiseaseJpaDao extends JpaRepository<Diseases,Integer>{

}
