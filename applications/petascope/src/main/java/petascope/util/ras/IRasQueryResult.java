/*
 * This file is part of rasdaman community.
 *
 * Rasdaman community is free software: you can redistribute it and/or modify
 * it under the terms of the GNU  General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * Rasdaman community is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU  General Public License for more details.
 *
 * You should have received a copy of the GNU  General Public License
 * along with rasdaman community.  If not, see <http://www.gnu.org/licenses/>.
 *
 * Copyright 2003 - 2010 Peter Baumann / rasdaman GmbH.
 *
 * For more information please see <http://www.rasdaman.org>
 * or contact Peter Baumann via <baumann@rasdaman.com>.
 */



package petascope.util.ras;

import rasj.RasGMArray;

/**
 * A rasdaman query result holder.
 * 
 * @author Dimitar Misev
 */
public interface IRasQueryResult {

    /**
     * @return the original result
     */
    Object getResult();

    /**
     * Inspect the original result, by executing the relevant methods bellow (mdd, scalar, integer, oid)
     */
    void inspect();

    /**
     * Executed when the result contains mdds
     */
    void mdd(RasGMArray res);

    /**
     * Executed when the result contains scalars
     */
    void scalar(Object res);
}
