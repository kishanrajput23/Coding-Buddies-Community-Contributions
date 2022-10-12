package com.cg.healthreminder.controller;

import java.util.List;

import javax.validation.Valid;
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
import com.cg.healthreminder.model.Diseases;
import com.cg.healthreminder.services.DiseaseServices;

/**
 * @ShaniaDalal
 * 
 * This is the Controller Class for Diseases model
 */
@CrossOrigin(origins = "http://localhost:3000")
@RestController
@RequestMapping("/healthreminder")
@SuppressWarnings("rawtypes")
@Validated
public class DiseaseController {
	
	@Autowired
	private DiseaseServices diseaseServices;
	
	/**
	 * Finds a Disease
	 * @param id value for disease
	 * @throws AllCustomException if id doesn't exist
	 */
	@GetMapping("/viewDisease/{id}")
	public Diseases viewDisease(@PathVariable @Min(1) Integer id) throws AllCustomException{
		return this.diseaseServices.viewDisease(id);
	}
	
	/**
	 * Shows all Diseases
	 * @throws AllCustomException if id doesn't exist
	 */
	@GetMapping("/viewDisease")
	public List<Diseases> displayAllDiseases() throws AllCustomException{
		return (List<Diseases>) this.diseaseServices.displayAllDiseases();
	}
	
	/**
	 * Adds new Disease
	 * @param id value for disease
	 */
	@SuppressWarnings("unchecked")
	@PostMapping(value="/addDisease")
	public ResponseEntity addDisease(@Valid @RequestBody Diseases d) {
		this.diseaseServices.addDisease(d);
		return new ResponseEntity("Disease added successfully", HttpStatus.OK);
	}
	
	/**
	 * Updates Disease Information
	 * @param id value, string for info
	 * @throws AllCustomException if id doesn't exist
	 */
	@SuppressWarnings("unchecked")
	@PostMapping("/updateDisease/{id}/{content}")
	public ResponseEntity updateDiseaseInfo(@PathVariable("id") @Min(1) Integer id,
			@PathVariable("content") @NotNull @Pattern(regexp = ".*[a-zA-Z]+.*",message="Please enter atleast one Alphabet") String content ) 
					throws AllCustomException{
		this.diseaseServices.updateDiseaseInfo(id, content);
		return new ResponseEntity("Disease Information Updated successfully", HttpStatus.OK);

	}
	
	/**
	 * Deletes Disease
	 * @param id value for disease
	 * @throws AllCustomException if id doesn't exist
	 */
	@SuppressWarnings("unchecked")
	@DeleteMapping(value="/deleteDisease/{id}")
	public ResponseEntity deleteDisease(@PathVariable @Min(1) Integer id) throws AllCustomException{
		this.diseaseServices.deleteDisease(id);
		return new ResponseEntity("Disease deleted successfully", HttpStatus.OK);
	}
	
	

}