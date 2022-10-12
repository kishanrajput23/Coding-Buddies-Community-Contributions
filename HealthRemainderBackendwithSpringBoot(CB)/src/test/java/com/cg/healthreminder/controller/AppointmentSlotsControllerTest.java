/**
 * @SayantanDas
 * 
 * This is the Controller Testing Class for AppointmentSlots.
*/

package com.cg.healthreminder.controller;
import com.cg.healthreminder.model.AppointmentSlots;
import com.cg.healthreminder.model.SlotCompositeKey;
import com.cg.healthreminder.services.AppointmentSlotsServices;
import com.fasterxml.jackson.core.JsonProcessingException;
import com.fasterxml.jackson.databind.ObjectMapper;
import org.junit.Assert;
import org.junit.Test;
import org.junit.runner.RunWith;
import org.mockito.Mockito;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.boot.test.autoconfigure.web.servlet.WebMvcTest;
import org.springframework.boot.test.mock.mockito.MockBean;
import org.springframework.http.HttpStatus;
import org.springframework.http.MediaType;
import org.springframework.mock.web.MockHttpServletResponse;
import org.springframework.test.context.junit4.SpringRunner;
import org.springframework.test.web.servlet.MockMvc;
import org.springframework.test.web.servlet.MvcResult;
import org.springframework.test.web.servlet.request.MockMvcRequestBuilders;

import static org.assertj.core.api.Assertions.assertThat;

import java.util.ArrayList;
import java.util.List;

@RunWith(SpringRunner.class)
@WebMvcTest(value = AppointmentSlotsController.class)
public class AppointmentSlotsControllerTest {
	
	  @Autowired
	  private MockMvc mockMvc;

	  @MockBean
	  private AppointmentSlotsServices appointmentSlotsService;
	    
	    /**
	     * Convert Object into Json String by using Jackson ObjectMapper
	     * @param appointmentSlots
	     * @return
	     * @throws JsonProcessingException
	     */
	    private String converttoJson(Object appointmentSlots) throws JsonProcessingException {
	        ObjectMapper objectMapper = new ObjectMapper();
	        return objectMapper.writeValueAsString(appointmentSlots);
	    }
	    
	    /**
		 * 
		 * To check if a new appointment slot gets created
		*/
	    @Test
	    public void testNewAppointmentSlot() throws Exception{
	        String URI = "/healthreminder/createAppointmentSlot";
	        AppointmentSlots slot2= new AppointmentSlots();
			SlotCompositeKey pk2=new SlotCompositeKey();
			pk2.setDoctorDate("12/17/2020");
			pk2.setDoctorId(12);
			slot2.setPk(pk2);
            slot2.setDoctorName("Naman");
			slot2.setDoctorEndTime("12:00");
			slot2.setDoctorStartTime("9:00");
			String jsonInput = this.converttoJson(slot2);

	        Mockito.when(appointmentSlotsService.createAppointmentSlot(Mockito.any(AppointmentSlots.class))).thenReturn(slot2);
	        MvcResult mvcResult = this.mockMvc.perform(MockMvcRequestBuilders.post(URI).accept(MediaType.APPLICATION_JSON).content(jsonInput).contentType(MediaType.APPLICATION_JSON))
	                .andReturn();
	        MockHttpServletResponse mockHttpServletResponse = mvcResult.getResponse();
	        String jsonOutput = mockHttpServletResponse.getContentAsString();
	        assertThat(jsonInput).isEqualTo(jsonOutput);
	        Assert.assertEquals(HttpStatus.OK.value(), mockHttpServletResponse.getStatus());
	    }
	    
	    /**
		 * 
		 * To check if All slots are displayed
		*/
	    @Test
	    public void testGetAllSlots() throws Exception{
	        String URI = "/healthreminder/getAllSlots";
	        AppointmentSlots slot= new AppointmentSlots();
	        slot.setDoctorName("Naman");
			 slot.setDoctorEndTime("12:00");
			 slot.setDoctorStartTime("9:00");
			 SlotCompositeKey pk=new SlotCompositeKey();
			 pk.setDoctorDate("12/16/2020");
			 pk.setDoctorId(1);
			 slot.setPk(pk);

	        AppointmentSlots slot2= new AppointmentSlots();
			SlotCompositeKey pk2=new SlotCompositeKey();
			pk2.setDoctorDate("12/17/2020");
			pk2.setDoctorId(12);
			slot2.setPk(pk2);
			slot2.setDoctorName("Naman");
			slot2.setDoctorEndTime("12:00");
			slot2.setDoctorStartTime("9:00");

	        List<AppointmentSlots> asl = new ArrayList<>();
	        asl.add(slot);
	        asl.add(slot2);

	        String jsonInput = this.converttoJson(asl);

	        Mockito.when(appointmentSlotsService.getAllSlots()).thenReturn(asl);
	        MvcResult mvcResult = this.mockMvc.perform(MockMvcRequestBuilders.get(URI).accept(MediaType.APPLICATION_JSON)).andReturn();
	        MockHttpServletResponse mockHttpServletResponse = mvcResult.getResponse();
	        String jsonOutput = mockHttpServletResponse.getContentAsString();

	        assertThat(jsonInput).isEqualTo(jsonOutput);
	    }
	    
	    /**
		 * 
		 * To check if Appointment SLot gets deleted.
		*/
	    
	 /*   @Test
	    public void testDeleteAppointmentSlot() throws Exception{
	    	 String URI = "/healthreminder/deleteAppointmentSlot";  
	    	 AppointmentSlots slot= new AppointmentSlots();
			 slot.setDoctorEndTime(null);
			 slot.setDoctorStartTime(null);
			 Slot_Pk pk=new Slot_Pk();
			 pk.setDoc_date("2020-12-16");
			 pk.setDoc_id(1);
			 slot.setPk(pk);
			 
	        
			Mockito.when(appointmentSlotsService.deleteAppointmentSlot(Mockito.any(AppointmentSlots.class))).thenReturn(slot);
	        MvcResult mvcResult = this.mockMvc.perform(MockMvcRequestBuilders.delete(URI).accept(MediaType.APPLICATION_JSON)).andReturn();
	        MockHttpServletResponse mockHttpServletResponse = mvcResult.getResponse();
	        Assert.assertEquals(HttpStatus.OK.value(), mockHttpServletResponse.getStatus());

	    }
*/

}
