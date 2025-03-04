package com.example.rest;

import com.example.model.Reserva;
import com.example.service.HotelService;
import com.example.service.HotelServiceImpl;

import jakarta.ws.rs.*;
import javax.ws.rs.core.MediaType;
import javax.ws.rs.core.Response;
import java.util.List;

@Path("/reservas")
public class ReservaResource {

    private HotelService hotelService = new HotelServiceImpl();

    @POST
    @Consumes(MediaType.APPLICATION_JSON)
    @Produces(MediaType.APPLICATION_JSON)
    public Response registrarReserva(Reserva reserva) {
        int numeroReserva = hotelService.registrarReserva(reserva);
        return Response.ok(numeroReserva).build();
    }

    @DELETE
    @Path("/{numeroReserva}")
    @Produces(MediaType.APPLICATION_JSON)
    public Response cancelarReserva(@PathParam("numeroReserva") int numeroReserva) {
        boolean cancelada = hotelService.cancelarReserva(numeroReserva);
        return Response.ok(cancelada).build();
    }

    @PUT
    @Path("/{numeroReserva}/efetivar")
    @Produces(MediaType.APPLICATION_JSON)
    public Response efetivarReserva(@PathParam("numeroReserva") int numeroReserva) {
        boolean efetivada = hotelService.efetivarReserva(numeroReserva);
        return Response.ok(efetivada).build();
    }

    @GET
    @Path("/{numeroReserva}")
    @Produces(MediaType.APPLICATION_JSON)
    public Response consultarReserva(@PathParam("numeroReserva") int numeroReserva) {
        Reserva reserva = hotelService.consultarReserva(numeroReserva);
        return Response.ok(reserva).build();
    }

    @GET
    @Produces(MediaType.APPLICATION_JSON)
    public Response listarReservas() {
        List<Reserva> reservas = hotelService.listarReservas();
        return Response.ok(reservas).build();
    }
}
