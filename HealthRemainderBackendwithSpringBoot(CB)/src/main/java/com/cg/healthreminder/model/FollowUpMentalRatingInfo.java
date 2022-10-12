package com.cg.healthreminder.model;

import javax.persistence.Column;
import javax.persistence.Entity;
import javax.persistence.Id;
import javax.persistence.Table;
import javax.validation.constraints.Min;
import javax.validation.constraints.Max;

/**
 * @ParthGoel
 *
 * This is the model class for Follow Up Mental Rating Information
 */

@Entity
@Table(name = "Followup_Mental_Rating_Info")
public class FollowUpMentalRatingInfo {

	@Override
	public String toString() {
		return "DietInfo [ patientId = " + patientId + ", mentalRating=" + mentalRating	+ "]";
	}
	
    @Id
    @Min(1)
	@Column(name = "patient_id", nullable = false)
    private Integer patientId;
    
    @Min(1)
    @Max(5)
    @Column(name = "mental_rating")
    private Integer mentalRating;   

	public Integer getPatientId() {
		return patientId;
	}

	public void setPatientId(Integer patientId) {
		this.patientId = patientId;
	}

	public Integer getMentalRating() {
		return mentalRating;
	}

	public void setMentalRating(Integer mentalRating) {
		this.mentalRating = mentalRating;
	}		
	

}
