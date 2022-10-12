package com.cg.healthreminder.services;

import com.cg.healthreminder.exception.AllCustomException;
import com.cg.healthreminder.model.FollowUpDietStatusInfo;

/**
 * @ParthGoel
 *
 * This is the services class for Follow Up Diet status Information
 */

public interface FollowUpDietStatusInfoServices {
	
	FollowUpDietStatusInfo findDietStatusById(Integer patientId) throws AllCustomException;
	FollowUpDietStatusInfo updateDietStatusById(Integer patientId, Boolean dietStatus) throws AllCustomException;
	FollowUpDietStatusInfo createDietStatus(FollowUpDietStatusInfo followUpDietStatusInfo);
	boolean deleteDietStatus(Integer patientId) throws AllCustomException;

}
