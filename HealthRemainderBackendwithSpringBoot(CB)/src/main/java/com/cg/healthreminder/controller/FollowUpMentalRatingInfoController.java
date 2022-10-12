package com.cg.healthreminder.controller;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.web.bind.annotation.CrossOrigin;
import org.springframework.web.bind.annotation.DeleteMapping;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.PathVariable;
import org.springframework.web.bind.annotation.PostMapping;
import org.springframework.web.bind.annotation.PutMapping;
import org.springframework.web.bind.annotation.RequestBody;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RestController;
import org.apache.logging.log4j.LogManager;
import org.apache.logging.log4j.Logger;
import javax.validation.Valid;
import javax.validation.constraints.Max;
import javax.validation.constraints.Min;

import com.cg.healthreminder.exception.AllCustomException;
import com.cg.healthreminder.model.FollowUpMentalRatingInfo;
import com.cg.healthreminder.services.FollowUpMentalRatingInfoServices;

/**
 * @ParthGoel
 *
 * This is the model class for Follow Up Mental Rating Information
 */
@CrossOrigin(origins="http://localhost:3000")
@RestController
@RequestMapping("/healthreminder")
public class FollowUpMentalRatingInfoController {

	@Autowired
	private FollowUpMentalRatingInfoServices followUpMentalRatingInfoServices;
	private static final Logger logger=LogManager.getLogger(FollowUpMentalRatingInfoController.class);
	
	/**
	 * To find a particular follow up mental rating using id
	 */
	@GetMapping("/followup_mentalrating_find/{patientId}")
	public FollowUpMentalRatingInfo findMentalRatingById(@PathVariable @Min(1) Integer patientId) throws AllCustomException{
		logger.info("Finding mental rating information by ID in Controller........");
		return this.followUpMentalRatingInfoServices.findMentalRatingById(patientId);
	}
	
	/**
	 * To update follow up mental rating details using id
	 */
	@PutMapping("/followup_mentalrating_update/{patientId}/rating/{mentalRating}")
	public FollowUpMentalRatingInfo updateMentalRatingById(@PathVariable @Min(1) Integer patientId, @PathVariable @Min(1) @Max(5) Integer mentalRating) throws AllCustomException{
		logger.info("Updating mental rating information by ID in Controller........");
		return this.followUpMentalRatingInfoServices.updateMentalRatingById(patientId, mentalRating);
	}
		
	/**
	 * To create follow up mental rating details 
	 */
	@PostMapping("/create_followup_mentalrating")
	public FollowUpMentalRatingInfo createMentalRating(@Valid @RequestBody FollowUpMentalRatingInfo followUpMentalRatingInfo) {
		logger.info("Creating mental rating information in Controller........");
		return followUpMentalRatingInfoServices.createMentalRating(followUpMentalRatingInfo);
	}
		
	/**
	 * To delete follow up mental rating details using id
	 */
	@DeleteMapping("/delete_mentalrating_by_id/{patientId}")
    public boolean deleteMentalRating(@PathVariable @Min(1) Integer patientId) throws AllCustomException{
		logger.info("Deleting mental rating information by ID in Controller........");
        return followUpMentalRatingInfoServices.deleteMentalRating(patientId);
    }
}
