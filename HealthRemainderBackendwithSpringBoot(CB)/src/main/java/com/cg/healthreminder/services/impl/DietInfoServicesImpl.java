package com.cg.healthreminder.services.impl;

import java.util.Optional;

import org.apache.logging.log4j.LogManager;
import org.apache.logging.log4j.Logger;

import javax.transaction.Transactional;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;

import com.cg.healthreminder.dao.DietInfoJpaDao;
import com.cg.healthreminder.exception.AllCustomException;
import com.cg.healthreminder.model.DietInfo;
import com.cg.healthreminder.services.DietInfoServices;

/**
 * @ParthGoel
 *
 * This is the services implementation class for Diet Information
 */

@Service
@Transactional
public class DietInfoServicesImpl implements DietInfoServices{
	
	@Autowired
	private DietInfoJpaDao dietInfoJpaDao;
	private static final Logger logger=LogManager.getLogger(DietInfoServicesImpl.class);

	/**
	 * To find diet information details using bmi
	 */
	@Override
	public DietInfo findDietByBMI(Integer bmiValue) throws AllCustomException{
		logger.info("Finding diet information by BMI in Implementation........");
		Optional<DietInfo> di = dietInfoJpaDao.findById(bmiValue);
		DietInfo di2 = null;
		if(di.isPresent()) {
			di2 = di.get();
		}
		else {
			throw new AllCustomException("Diet Information not found for the given Patient id");
		}
		return di2;
	}

	/**
	 * To find all diet information details 
	 */
	@Override
	public Iterable<DietInfo> getAllDiets() {
		logger.info("Finding all diet information by BMI in Implementation........");
		return dietInfoJpaDao.findAll();
	}
	
	/**
	 * To update diet information details using bmi
	 */
	@Override
	public DietInfo updateDietByBMI(Integer bmiValue, String diet) throws AllCustomException{
		logger.info("Updating diet information by BMI in Implementation........");
		Optional<DietInfo> dietInfo = dietInfoJpaDao.findById(bmiValue);
		DietInfo di2 = null;
		if(dietInfo.isPresent()) {
			di2 = dietInfo.get();
			di2.setDiet(diet);
		}
		else {
			throw new AllCustomException("Diet Information not found for the given Patient id, so can't be updated");
		}
		return dietInfoJpaDao.save(di2);
		
	}

	/**
	 * To delete diet information details using bmi
	 */
	@Override
	public boolean deleteDietByBMI(Integer bmiValue) throws AllCustomException{
		logger.info("Deleting diet information by BMI in Implementation........");
		Optional<DietInfo> di = dietInfoJpaDao.findById(bmiValue);
		if(di.isPresent()) {
			dietInfoJpaDao.deleteById(bmiValue);
		}
		else {
			throw new AllCustomException("Diet Information not found for the given Patient id, so can't be deleted");	
		}
		
		
		return true;	
	}

	/**
	 * To create diet information details 
	 */
	@Override
	public DietInfo createDiet(DietInfo dietInfo) {
		logger.info("Creating diet information in Implementation........");
		return dietInfoJpaDao.save(dietInfo);
	}

}
