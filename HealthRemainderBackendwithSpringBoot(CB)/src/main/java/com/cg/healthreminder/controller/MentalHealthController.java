package com.cg.healthreminder.controller;

import java.util.List;

import javax.validation.Valid;
import javax.validation.constraints.Max;
import javax.validation.constraints.Min;
import javax.validation.constraints.NotNull;
import javax.validation.constraints.Pattern;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.http.HttpStatus;
import org.springframework.http.ResponseEntity;
import org.springframework.validation.annotation.Validated;
import org.springframework.web.bind.annotation.CrossOrigin;
import org.springframework.web.bind.annotation.DeleteMapping;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.PathVariable;
import org.springframework.web.bind.annotation.PostMapping;
import org.springframework.web.bind.annotation.RequestBody;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RestController;

import com.cg.healthreminder.exception.AllCustomException;
import com.cg.healthreminder.model.MentalHealth;
import com.cg.healthreminder.services.MentalHealthServices;

/**
 * @ShaniaDalal
 * 
 * This is the Controller Class for MentalHealth model
 */

@CrossOrigin(origins = "http://localhost:3000")
@RestController
@RequestMapping("/healthreminder")
@SuppressWarnings("rawtypes")
@Validated
public class MentalHealthController {
	
	@Autowired
	private MentalHealthServices mentalServices;
	
	/**
	 * Finds a Tip
	 * @param id value for rating 
	 * @throws AllCustomException if id doesn't exist
	 */
	@GetMapping("/viewTips/{id}")
	public MentalHealth displayTips(@PathVariable @Min(1) @Max(5) Integer id) throws AllCustomException{
		return this.mentalServices.displayTips(id);
	}
	
	/**
	 * Shows all Tips
	 * @throws AllCustomException if id doesn't exist
	 */
	@GetMapping("/viewTips")
	public List<MentalHealth> displayAllTips() throws AllCustomException{
		return (List<MentalHealth>) this.mentalServices.displayAllTips();
	}
	
	/**
	 * Adds a Tip
	 * @param id value for rating 
	 */
	@SuppressWarnings("unchecked")
	@PostMapping(value="/addTips")
	public ResponseEntity addTips(@Valid @RequestBody MentalHealth h) {
		this.mentalServices.addTips(h);
		return new ResponseEntity("Tip added successfully", HttpStatus.OK);
	}
	
	/**
	 * Updates a Tip
	 * @param id value, string for tip 
	 * @throws AllCustomException if id doesn't exist
	 */
	@SuppressWarnings("unchecked")
	@PostMapping("/updateTips/{id}/{content}")
	public ResponseEntity updateTips(@PathVariable("id") @Min(1) @Max(5) Integer id, 
			@PathVariable("content") @NotNull @Pattern(regexp = ".*[a-zA-Z]+.*",message="Please enter atleast one Alphabet") String content) throws AllCustomException{
		this.mentalServices.updateTips(id, content);
		return new ResponseEntity("Health Tip Updated successfully", HttpStatus.OK);

	}
	
	/**
	 * Deletes a Tip
	 * @param id value for rating 
	 * @throws AllCustomException if id doesn't exist
	 */
	@SuppressWarnings("unchecked")
	@DeleteMapping("/deleteTips/{id}")
	public ResponseEntity deleteTips(@PathVariable @Min(1) @Max(5) Integer id) throws AllCustomException{
		this.mentalServices.deleteTips(id);
		return new ResponseEntity("Health Tip deleted successfully", HttpStatus.OK);

	}
	
	
}
