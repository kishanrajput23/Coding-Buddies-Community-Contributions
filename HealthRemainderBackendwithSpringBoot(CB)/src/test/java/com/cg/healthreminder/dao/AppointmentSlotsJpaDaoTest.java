/**
 * @SayantanDas
 * 
 * This is the DAORepository Testing Class for AppointmentDetails.
*/

package com.cg.healthreminder.dao;
import org.junit.Test;
import org.junit.runner.RunWith;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.boot.test.autoconfigure.orm.jpa.DataJpaTest;
import org.springframework.boot.test.autoconfigure.orm.jpa.TestEntityManager;
import org.springframework.test.context.junit4.SpringRunner;
import org.junit.Assert;

import static org.assertj.core.api.Assertions.assertThat;

import java.util.List;


import com.cg.healthreminder.model.AppointmentSlots;
import com.cg.healthreminder.model.SlotCompositeKey;

@RunWith(SpringRunner.class)
@DataJpaTest
public class AppointmentSlotsJpaDaoTest {
	 @Autowired
     private TestEntityManager testEntityManager;
	 @Autowired
     private AppointmentSlotsJpaDao appointmentSlotsJpaDao;
	 
	 
	 private AppointmentSlots getAppointmentSlot() {
		 AppointmentSlots slot= new AppointmentSlots();
		 slot.setDoctorEndTime("12:00");
		 slot.setDoctorStartTime("9:00");
		 slot.setDoctorName("Naman");
		 SlotCompositeKey pk=new SlotCompositeKey();
		 pk.setDoctorDate("12/16/2020");
		 pk.setDoctorId(1);
		 slot.setPk(pk);
		 return slot;
	 }
	 
	 /**
	 * 
	 * To check if a new appointment slot gets created
	*/	 
	 @Test
	 public void testNewAppointmentSlot() throws Exception{
	     AppointmentSlots slot = getAppointmentSlot();
	     AppointmentSlots saveInDb = testEntityManager.persist(slot);
	     AppointmentSlots getFromInDb = appointmentSlotsJpaDao.findById(saveInDb.getPk()).get();
	     assertThat(getFromInDb).isEqualTo(saveInDb);
	     assertThat(getFromInDb.toString()).hasToString(saveInDb.toString());
	 }

	 /**
	 * 
	 * To check if Appointment SLot gets deleted.
	*/
	 @Test
	 public void testDeleteAppointmentSlot() throws Exception{
		 AppointmentSlots slot1 = getAppointmentSlot();
		 AppointmentSlots slot2= new AppointmentSlots();
		 slot2.setDoctorEndTime("12:00");
		 slot2.setDoctorStartTime("9:00");
		 slot2.setDoctorName("Naman");
		 SlotCompositeKey pk2=new SlotCompositeKey();
		 pk2.setDoctorDate("12/17/2020");
		 pk2.setDoctorId(12);
		 slot2.setPk(pk2);

		 AppointmentSlots appslot = testEntityManager.persist(slot1);
         testEntityManager.persist(slot2);
         testEntityManager.remove(appslot);

         List<AppointmentSlots> tickets = (List<AppointmentSlots>) appointmentSlotsJpaDao.findAll();
	     Assert.assertEquals(1,tickets.size());

	    }

	 
	 
	 /**
	 * 
	 * To check if All slots are displayed
	*/
	 @Test
	    public void testGetAllSlots() throws Exception{
		 AppointmentSlots slot1 = getAppointmentSlot();
		 AppointmentSlots slot2= new AppointmentSlots();
		 slot2.setDoctorEndTime("12:00");
		 slot2.setDoctorStartTime("9:00");
		 slot2.setDoctorName("Naman");
		 SlotCompositeKey pk2=new SlotCompositeKey();
		 pk2.setDoctorDate("12/17/2020");
		 pk2.setDoctorId(12);
		 slot2.setPk(pk2);

		 testEntityManager.persist(slot1);
         testEntityManager.persist(slot2);
      
         List<AppointmentSlots> tickets = (List<AppointmentSlots>) appointmentSlotsJpaDao.findAll();
	     Assert.assertEquals(2,tickets.size());
	    }
}
