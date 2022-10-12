package com.cg.healthreminder.services.impl;

import com.cg.healthreminder.exception.AllCustomException;

import org.apache.logging.log4j.LogManager;
import org.apache.logging.log4j.Logger;
import org.springframework.beans.factory.annotation.Autowired;

import com.cg.healthreminder.dao.MentalHealthJpaDao;
import com.cg.healthreminder.model.MentalHealth;
import com.cg.healthreminder.services.MentalHealthServices;

import org.springframework.stereotype.Service;

import java.util.Optional;

import javax.transaction.Transactional;

/**
 * @ShaniaDalal
 * 
 * This is the Service Implementation Class for MentalHealth model
 */

@Service
@Transactional
public class MentalHealthServicesImpl implements MentalHealthServices {
	
	@Autowired
	MentalHealthJpaDao mentalDao;
	private static final Logger logger=LogManager.getLogger(MentalHealthServicesImpl.class);
	
	/**
	 * Finds a Tip
	 * @param id value for rating 
	 * @throws AllCustomException if id doesn't exist
	 */
	@Override
	public MentalHealth displayTips(Integer mentalRating) throws AllCustomException{
		logger.info("Finding Mental Health Tip using the Rating ........");
		Optional<MentalHealth> m = mentalDao.findById(mentalRating);
		MentalHealth m2 = null;
		if(m.isPresent()) {
			m2 = m.get();
		}
		else {
			logger.info("Exception Thrown while finding-----");
			throw new AllCustomException("Health Rating Record not found for given ID");
		}
		logger.info("Returning Tip-----");
		return m2;
	}
	
	/**
	 * Views All Tips
	 * @throws AllCustomException if id doesn't exist
	 */
	@Override
	public Iterable<MentalHealth> displayAllTips() throws AllCustomException{
		logger.info("Returning All Tips-----");
		return mentalDao.findAll();
	}
	
	/**
	 * Updates a Tip
	 * @param id value, string for tip 
	 * @throws AllCustomException if id doesn't exist
	 */
	@Override
	public MentalHealth updateTips(Integer mentalRating, String uptips) throws AllCustomException{
		logger.info("Updating Mental Health Tip using the Rating ........");
		Optional<MentalHealth> m= mentalDao.findById(mentalRating);
		MentalHealth m2 = null;
		if(m.isPresent()) {
			m2 = m.get();
		}
		else {
			logger.info("Exception Thrown while updating-----");
			throw new AllCustomException("Health Rating not found for given ID, cannot update Tip");
		}
        m2.setMentalTip(uptips);
        logger.info("Returning Updating Value-----");
        return mentalDao.save(m2);
	}
	
	/**
	 * Adds a Tip
	 * @param id value for rating 
	 */
	@Override
	public MentalHealth addTips(MentalHealth m) {
		logger.info("Adding new Mental Health Tip ........");
		logger.info("Returning MentalHealth-----");
		return mentalDao.save(m);
		
	}
	
	/**
	 * Deletes a Tip
	 * @param id value for rating 
	 * @throws AllCustomException if id doesn't exist
	 */
	@Override
	public boolean deleteTips(Integer mentalRating) throws AllCustomException{
		logger.info("Deleting Mental Health Tip using the Rating ........");
		Optional<MentalHealth> m=mentalDao.findById(mentalRating);
		if(m.isPresent()) {
			mentalDao.deleteById(mentalRating);
		}
		else {
			logger.info("Exception Thrown while deleting-----");
			throw new AllCustomException("Health Rating not found for given ID, cannot delete");
		}
		logger.info("Returning True for Deletion-----");
		return true;
	}
	
}
