package com.cg.healthreminder.model;

import javax.persistence.Column;
import javax.persistence.Entity;
import javax.persistence.Id;
import javax.persistence.Table;
import javax.validation.constraints.Min;

/**
 * @ParthGoel
 *
 * This is the model class for Follow Up Diet status Information
 */

@Entity
@Table(name = "Followup_Diet_Status_Info")
public class FollowUpDietStatusInfo {
	
	@Override
	public String toString() {
		return "DietInfo [ patientId = " + patientId + ", dietStatus = " + dietStatus + ", streak = " + streak + "]";
	}
	
	// Patient ID
    @Id
    @Min(1)
	@Column(name = "patient_id", nullable = false)
    private Integer patientId;
    
    // Status of Diet
    @Column(name = "diet_status")
    private Boolean dietStatus;
    
    // Streak
    @Column(name = "streak")
    private Integer streak;
    
	public FollowUpDietStatusInfo() {
		this.streak = 0;
	}

	public Integer getPatientId() {
		return patientId;
	}

	public void setPatientId(Integer patientId) {
		this.patientId = patientId;
	}

	public Boolean getDietStatus() {
		return dietStatus;
	}

	public void setDietStatus(Boolean dietStatus) {
		boolean ds = dietStatus.booleanValue();
		if(ds) {
			this.streak++;
		}
		else {
			this.streak = 0;
		}
		this.dietStatus = dietStatus;
	}

	public Integer getStreak() {
		return streak;
	}

	public void setStreak(Integer streak) {
		this.streak = streak;
	}
    
}
