package com.cg.healthreminder.services;

import com.cg.healthreminder.exception.AllCustomException;
import com.cg.healthreminder.model.Diseases;

/**
 * @ShaniaDalal
 * 
 * This is the Services Class for Diseases model
 */

public interface DiseaseServices {
	public Diseases viewDisease(Integer diseaseId) throws AllCustomException;
	public Iterable<Diseases> displayAllDiseases() throws AllCustomException;
	public Diseases updateDiseaseInfo(Integer diseaseId, String content) throws AllCustomException;
	public Diseases addDisease(Diseases d);
	public boolean deleteDisease(Integer diseaseId) throws AllCustomException;
}
