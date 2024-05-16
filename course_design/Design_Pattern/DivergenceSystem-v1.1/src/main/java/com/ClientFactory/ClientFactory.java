package com.ClientFactory;

import java.io.IOException;

public class ClientFactory {
    public static Client createClient(String type) throws IOException {
        if (type.equalsIgnoreCase("student")) {
            return new ClientStuVer();
        } else if (type.equalsIgnoreCase("teacher")) {
            return new ClientTeaVer();
        } else {
            throw new IllegalArgumentException("Invalid client type");
        }
    }
}
