package com.cg.healthreminder.controller;

/* @author Naman Bhandari*/

import java.util.List;

import org.apache.logging.log4j.LogManager;
import org.apache.logging.log4j.Logger;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.web.bind.annotation.DeleteMapping;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.PathVariable;
import org.springframework.web.bind.annotation.PostMapping;
import org.springframework.web.bind.annotation.PutMapping;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RestController;

import com.cg.healthreminder.exception.AllCustomException;
import com.cg.healthreminder.model.MedicalHistory;
import com.cg.healthreminder.services.MedicalHistoryService;

@RestController
@RequestMapping("/healthreminder")
public class MedicalHistoryController {
	@Autowired
	private MedicalHistoryService medicalHistoryService;
	private static final Logger logger=LogManager.getLogger(MedicalHistoryController.class);

	/*To get all records for a patient*/ 
	@GetMapping("/records/{id}")
	public List<MedicalHistory> getByPatientId(@PathVariable int id) throws AllCustomException{
		logger.info("cont:Fetching medical records by patientid");
		return this.medicalHistoryService.getByPatientId(id);
	}
	
	/*To add a new record*/
	@PostMapping("/addrecord")
	public MedicalHistory addRecord(MedicalHistory m) throws AllCustomException{
		logger.info("cont:adding new medical record");
		return this.medicalHistoryService.addRecord(m);
	}
	
	/*To delete a particular record*/
	@DeleteMapping("/delrecord")
	public void delRecord(String file) {
		logger.info("cont:deleting medical record");
		this.medicalHistoryService.deleteRecord(file);
	}
	
	/*To update a record*/
	@PutMapping("/record")
	public MedicalHistory updateRecord(MedicalHistory m) throws AllCustomException {
		logger.info("cont:updating medical record");

		return this.medicalHistoryService.updateRecord(m);
	}
}
