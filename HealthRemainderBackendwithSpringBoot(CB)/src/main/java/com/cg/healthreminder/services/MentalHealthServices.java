package com.cg.healthreminder.services;

import com.cg.healthreminder.exception.AllCustomException;
import com.cg.healthreminder.model.MentalHealth;

/**
 * @ShaniaDalal
 * 
 * This is the Services Class for MentalHealth model
 */

public interface MentalHealthServices {
	public MentalHealth displayTips(Integer mentalRating) throws AllCustomException;
	public Iterable<MentalHealth> displayAllTips() throws AllCustomException;
	public MentalHealth updateTips(Integer mentalRating, String uptips) throws AllCustomException;
	public MentalHealth addTips(MentalHealth m);
	public boolean deleteTips(Integer mentalRating) throws AllCustomException;
}
