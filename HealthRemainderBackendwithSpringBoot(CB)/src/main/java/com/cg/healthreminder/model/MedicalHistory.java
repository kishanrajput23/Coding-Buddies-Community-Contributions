package com.cg.healthreminder.model;

/* @author Naman Bhandari*/

import javax.persistence.*;

@Entity
@Table(name="medhistory")
public class MedicalHistory {
	
	@Id
	@Column(name="file")
	private String file;
	@Column(name="patient_id")
	private int patientId;
	@Column(name="notes")
	private String notes;
	
	
	/* Setters and Getters*/
	public String getFile() {
		return file;
	}
	public void setFile(String file) {
		this.file = file;
	}
	public int getPatientId() {
		return patientId;
	}
	public void setPatientId(int patientId) {
		this.patientId = patientId;
	}
	public String getNotes() {
		return notes;
	}
	public void setNotes(String notes) {
		this.notes = notes;
	}
	@Override
	public String toString() {
		return "MedicalHistory [file=" + file + ", patientId=" + patientId + ", notes=" + notes + "]";
	}
	
}
