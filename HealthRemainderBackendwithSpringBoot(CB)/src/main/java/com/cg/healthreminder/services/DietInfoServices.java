package com.cg.healthreminder.services;

import com.cg.healthreminder.exception.AllCustomException;
import com.cg.healthreminder.model.DietInfo;

/**
 * @ParthGoel
 *
 * This is the services class for Diet status Information
 */

public interface DietInfoServices {

	DietInfo findDietByBMI(Integer bmiValue) throws AllCustomException;
	Iterable<DietInfo> getAllDiets();
	DietInfo updateDietByBMI(Integer bmiValue, String diet) throws AllCustomException;
	boolean deleteDietByBMI(Integer bmiValue) throws AllCustomException;
	DietInfo createDiet(DietInfo dietInfo);
	
}
