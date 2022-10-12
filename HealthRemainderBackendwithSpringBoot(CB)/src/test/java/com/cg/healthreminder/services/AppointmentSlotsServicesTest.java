/**
 * @SayantanDas
 * 
 * This is the Service Testing Class for AppointmentSlots.
*/

package com.cg.healthreminder.services;
import org.junit.Test;
import org.junit.runner.RunWith;
import org.mockito.Mockito;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.boot.test.context.SpringBootTest;
import org.springframework.boot.test.mock.mockito.MockBean;
import org.springframework.test.context.junit4.SpringRunner;

import com.cg.healthreminder.dao.AppointmentSlotsJpaDao;
import com.cg.healthreminder.model.AppointmentSlots;
import com.cg.healthreminder.model.SlotCompositeKey;

import java.util.ArrayList;
import java.util.List;

import static org.assertj.core.api.Assertions.assertThat;

@RunWith(SpringRunner.class)
@SpringBootTest

public class AppointmentSlotsServicesTest {
	 @MockBean
	  private AppointmentSlotsJpaDao appointmentSlotsJpaDao;

	  @Autowired
	  private AppointmentSlotsServices appointmentSlotServices;
	  
	  
	/**
	 * 
	 * To check if a new appointment slot gets created
	*/
	  @Test
	  public void testCreateAppointmentSlot(){
		  AppointmentSlots slot= new AppointmentSlots();
		  slot.setDoctorEndTime("12:00");
		  slot.setDoctorStartTime("9:00");
		  slot.setDoctorName("Naman");
		  SlotCompositeKey pk=new SlotCompositeKey();
		  pk.setDoctorDate("12/16/2020");
		  pk.setDoctorId(1);
		  slot.setPk(pk);
		  Mockito.when(appointmentSlotsJpaDao.save(slot)).thenReturn(slot);
		  assertThat(appointmentSlotServices.createAppointmentSlot(slot)).isEqualTo(slot);
	    }
	  
	  
	  /**
		 * 
		 * To check if All slots are displayed
		*/	  
	   @Test
	    public void testGetAllBookedTickets() throws Exception{
		   AppointmentSlots slot= new AppointmentSlots();
		   slot.setDoctorEndTime("12:00");
		   slot.setDoctorStartTime("9:00");
		   slot.setDoctorName("Naman");
		   SlotCompositeKey pk=new SlotCompositeKey();
		   pk.setDoctorDate("12/16/2020");
		   pk.setDoctorId(1);
		   slot.setPk(pk);
		   AppointmentSlots slot2= new AppointmentSlots();
		   slot2.setDoctorEndTime("12:00");
		   slot2.setDoctorStartTime("9:00");
		   slot2.setDoctorName("Naman");
		   SlotCompositeKey pk2=new SlotCompositeKey();
		   pk2.setDoctorDate("12/17/2020");
		   pk2.setDoctorId(12);
		   slot2.setPk(pk2);
	       
		   List<AppointmentSlots> asl = new ArrayList<>();
	       asl.add(slot);
	       asl.add(slot2);

	        Mockito.when(appointmentSlotsJpaDao.findAll()).thenReturn(asl);
	        assertThat(appointmentSlotServices.getAllSlots()).isEqualTo(asl);
	    }
}
