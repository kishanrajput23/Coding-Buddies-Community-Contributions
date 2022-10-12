package com.cg.healthreminder.controller;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.validation.annotation.Validated;
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
import com.cg.healthreminder.model.DietInfo;
import com.cg.healthreminder.services.DietInfoServices;

/**
 * @ParthGoel
 *
 * This is the controller class for Diet Information
 */

@CrossOrigin(origins = "http://localhost:3000")
@RestController
@RequestMapping("/healthreminder")
@Validated
public class DietInfoController {

	@Autowired
	private DietInfoServices dietInfoService;
	private static final Logger logger=LogManager.getLogger(DietInfoController.class);
	
	/**
	 * To find a particular diet using bmi
	 */
	@GetMapping("/diet_info_find/{bmi}")
	public DietInfo findDietByBMI(@PathVariable @Min(1) @Max(4) Integer bmi) throws AllCustomException{
		logger.info("Finding diet information by BMI in Controller........");
		return this.dietInfoService.findDietByBMI(bmi);
	}
	
	/**
	 * To find list of all diets
	 */
	@GetMapping("/diet_info_find_all")
	public Iterable<DietInfo> getAllDiets(){
		logger.info("Finding all diet information by BMI in Controller........");
		return this.dietInfoService.getAllDiets();
	}
	
	/**
	 * To update diet details by bmi
	 */
	@PutMapping("/diet_info_update/{bmiValue}/info/{dietInformation}")
	public DietInfo updateDietByBMI(@PathVariable @Min(1) @Max(4) Integer bmiValue, @PathVariable String dietInformation) throws AllCustomException{
		logger.info("Updating diet information by BMI in Controller........");
		return this.dietInfoService.updateDietByBMI(bmiValue, dietInformation);
	}
	
	/**
	 * To delete diet details by bmi
	 */
	@DeleteMapping("/delete_diet_by_bmi/{bmiValue}")
    public boolean deleteDietByBMI(@PathVariable @Min(1) @Max(4) Integer bmiValue) throws AllCustomException{
		logger.info("Deleting diet information by BMI in Controller........");
        return dietInfoService.deleteDietByBMI(bmiValue);
    }
	
	/**
	 * To create diet details
	 */
	 @PostMapping("/create_diet")
	 public DietInfo createDiet(@Valid @RequestBody DietInfo dietInfo) {
		 logger.info("Deleting diet information in Controller........");
		 return dietInfoService.createDiet(dietInfo);
	 }
	
}
