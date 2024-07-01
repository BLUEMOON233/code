package com.ClientFactory;

import java.io.IOException;

public class ClientFactory {
    public static Client createClient(String type) throws IOException {
        if (type.equalsIgnoreCase("student")) {
            System.out.printf("The client is created by the ClientFactory\n");
            System.out.printf("parameter: %s", type);
            System.out.printf("output type: student\n");
            return new ClientStuVer();
        } else if (type.equalsIgnoreCase("teacher")) {
            System.out.printf("The client is created by the ClientFactory\n");
            System.out.printf("parameter: %s", type);
            System.out.printf("output type: teacher\n");
            return new ClientTeaVer();
        } else {
            throw new IllegalArgumentException("Invalid client type");
        }
    }
}
