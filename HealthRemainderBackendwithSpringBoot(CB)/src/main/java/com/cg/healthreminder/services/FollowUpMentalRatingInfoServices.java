package com.cg.healthreminder.services;

import com.cg.healthreminder.exception.AllCustomException;
import com.cg.healthreminder.model.FollowUpMentalRatingInfo;

/**
 * @ParthGoel
 *
 * This is the services class for Follow Up Mental Rating Information
 */
public interface FollowUpMentalRatingInfoServices {

	FollowUpMentalRatingInfo findMentalRatingById(Integer patientId) throws AllCustomException;
	FollowUpMentalRatingInfo updateMentalRatingById(Integer patientId, Integer mentalRating) throws AllCustomException;
	FollowUpMentalRatingInfo createMentalRating(FollowUpMentalRatingInfo followUpMentalRatingInfo);
	boolean deleteMentalRating(Integer patientId) throws AllCustomException;
}
