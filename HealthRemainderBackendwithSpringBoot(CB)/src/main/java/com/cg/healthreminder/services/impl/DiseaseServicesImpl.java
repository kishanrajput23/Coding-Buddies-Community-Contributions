package com.cg.healthreminder.services.impl;

import java.util.Optional;

import javax.transaction.Transactional;

import org.apache.logging.log4j.LogManager;
import org.apache.logging.log4j.Logger;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;

import com.cg.healthreminder.dao.DiseaseJpaDao;
import com.cg.healthreminder.exception.AllCustomException;
import com.cg.healthreminder.model.Diseases;
import com.cg.healthreminder.services.DiseaseServices;

/**
 * @ShaniaDalal
 * 
 * This is the Service Implementation Class for Diseases model
 */

@Service
@Transactional
public class DiseaseServicesImpl implements DiseaseServices{
	@Autowired
	private DiseaseJpaDao diseaseDao;
	private static final Logger logger=LogManager.getLogger(DiseaseServicesImpl.class);
	
	/**
	 * Finds a Disease
	 * @param id value for disease
	 * @throws AllCustomException if id doesn't exist
	 */
	@Override
	public Diseases viewDisease(Integer diseaseId) throws AllCustomException {
		logger.info("Finding Disease using Disease ID ........");
		Optional<Diseases> d= diseaseDao.findById(diseaseId);
		Diseases d2 = null;
		if(d.isPresent()) {
			d2 = d.get();
		}
		else {
			logger.info("Exception Thrown while finding-----");
			throw new AllCustomException("Disease not found for given ID");
		}
		logger.info("Returning Disease Value-----");
		return d2;
	}
	
	/**
	 * Views All Disease
	 * @throws AllCustomException if id doesn't exist
	 */
	public Iterable<Diseases> displayAllDiseases() throws AllCustomException{
		logger.info("Returning All Diseases-----");
		return diseaseDao.findAll();
	}
	
	/**
	 * Updates Disease Information
	 * @param id value, string for info
	 * @throws AllCustomException if id doesn't exist
	 */
	@Override
	public Diseases updateDiseaseInfo(Integer diseaseId, String content) throws AllCustomException{
		logger.info("Updating Disease using Disease ID ........");
		Optional<Diseases> d= diseaseDao.findById(diseaseId);
		Diseases d2 = null;
		if(d.isPresent()) {
			d2 = d.get();
		}
		else {
			logger.info("Exception Thrown while Updating-----");
			throw new AllCustomException("Disease not found for given ID, cannot update Info.");
		}
        d2.setDiseaseInfo(content);
        logger.info("Returning Updated Value-----");
        return diseaseDao.save(d2);
	}

	/**
	 * Adds new Disease
	 * @param id value for disease
	 */
	@Override
	public Diseases addDisease(Diseases d) {
		logger.info("Adding new Disease........");
		logger.info("Returning New Disease-----");
		return diseaseDao.save(d);
		
	}
	
	/**
	 * Deletes Disease
	 * @param id value for disease
	 * @throws AllCustomException if id doesn't exist
	 */
	@Override
	public boolean deleteDisease(Integer diseaseId) throws AllCustomException{
		logger.info("Deleting Disease using Disease ID ........");
		Optional<Diseases> m=diseaseDao.findById(diseaseId);
		if(m.isPresent()) {
			diseaseDao.deleteById(diseaseId);
		}
		else {
			logger.info("Exception Thrown while Deleting-----");
			throw new AllCustomException("Disease not found for given ID, cannot delete");
		}
		logger.info("Returning True for Deletion-----");
		return true;
	}

}