package com.cg.healthreminder.controller;

/* @author Naman Bhandari*/

import java.util.List;

import javax.validation.Valid;

import org.apache.logging.log4j.LogManager;
import org.apache.logging.log4j.Logger;
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

import com.cg.healthreminder.exception.AllCustomException;
import com.cg.healthreminder.model.Patient;
import com.cg.healthreminder.services.PatientService;

@CrossOrigin(origins = "http://localhost:3000")
@RestController
@RequestMapping("/healthreminder")
public class PatientController {
	@Autowired
	private PatientService patientService;
	private static final Logger logger=LogManager.getLogger(PatientController.class);

	/*To find list of all patients*/
	@GetMapping("/patients")
	public List<Patient> getPatients(){
		logger.info("cont: fetching all patients");
		return this.patientService.getAllPatients();
	}
	
	/*To find a particular patient details using its id*/
	@GetMapping("/patient/{id}")
	public Patient getPatient(@PathVariable int id) throws AllCustomException{
		logger.info("cont: getting patient by id");
		return this.patientService.getPatient(id);
	}
	
	/*To add new patient*/
	@PostMapping("/patient")
	public Patient addPatient(@Valid @RequestBody Patient p) throws AllCustomException{
		logger.info("cont: adding patient");
		return this.patientService.addPatient(p);
	}
	
	/*To update patient details*/
	@PutMapping("/patient")
	public Patient updatePatient(Patient p) throws AllCustomException{
		logger.info("cont: updating patient");
		return this.patientService.updatePatient(p);
	}
	
	/*To delete a patient*/
	@DeleteMapping("/patient/{id}")
	public void deletePatient(@PathVariable int id) {
		logger.info("cont: deleting patient");
		this.patientService.deletePatientById(id);
	}
}
