package com.cg.healthreminder.controller;

import org.springframework.beans.factory.annotation.Autowired;
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
import javax.validation.constraints.Min;

import com.cg.healthreminder.exception.AllCustomException;
import com.cg.healthreminder.model.FollowUpDietStatusInfo;
import com.cg.healthreminder.services.FollowUpDietStatusInfoServices;

/**
 * @ParthGoel
 *
 * This is the controller class for Follow Up Diet status Information
 */

@RestController
@RequestMapping("/healthreminder")
public class FollowUpDietStatusInfoController {

	@Autowired
	private FollowUpDietStatusInfoServices followUpDietStatusInfoServices;
	private static final Logger logger=LogManager.getLogger(FollowUpDietStatusInfoController.class);
	
	/**
	 * To find a particular follow up diet status using id
	 */
	@GetMapping("/followup_dietstatus_find/{patientId}")
	public FollowUpDietStatusInfo findDietStatusById(@PathVariable @Min(1) Integer patientId) throws AllCustomException{
		logger.info("Finding diet status information by ID in Controller........");
		return this.followUpDietStatusInfoServices.findDietStatusById(patientId);
	}
	
	/**
	 * To update follow up diet status details using  ID 
	 */
	@PutMapping("/followup_dietstatus_update/{patientId}/status/{dietStatus}")
	public FollowUpDietStatusInfo updateDietStatusById(@PathVariable @Min(1) Integer patientId, @PathVariable Boolean dietStatus) throws AllCustomException{
		logger.info("Updating diet status information by ID in Controller........");
		return this.followUpDietStatusInfoServices.updateDietStatusById(patientId, dietStatus);
	}
	
	/**
	 * To create follow up diet details
	 */
	@PostMapping("/create_followup_dietstatus")
	public FollowUpDietStatusInfo createDietStatus(@Valid @RequestBody FollowUpDietStatusInfo followUpDietStatusInfo) {
		logger.info("Creating diet status information in Controller........");
		return followUpDietStatusInfoServices.createDietStatus(followUpDietStatusInfo);
	}
	
	/**
	 * To delete follow up diet status details using ID 
	 */
	@DeleteMapping("/delete_dietstatus_by_id/{patientId}")
    public boolean deleteDietStatus(@PathVariable @Min(1) Integer patientId) throws AllCustomException{
		logger.info("Deleting diet status information by ID in Controller........");
        return followUpDietStatusInfoServices.deleteDietStatus(patientId);
    }

	
}
