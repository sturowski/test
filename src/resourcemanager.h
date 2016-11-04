/*
    Copyright (c) 2016 Sven Turowski <sventurowski@gmx.de>
    
    Created on 31.10.16

    This file is part of tools, a C++ collection.

    cppsql is free software; you can redistribute it and/or modify it under
    the terms of the GNU Lesser General Public License (LGPL) as published
    by the Free Software Foundation; either version 3 of the License, or
    (at your option) any later version.

    As a special exception, the Contributors give you permission to link
    this library with independent modules to produce an executable,
    regardless of the license terms of these independent modules, and to
    copy and distribute the resulting executable under terms of your choice,
    provided that you also meet, for each linked independent module, the
    terms and conditions of the license of that module. An independent
    module is a module which is not derived from or based on this library.
    If you modify this library, you must extend this exception to your
    version of the library.

    cppsql is distributed in the hope that it will be useful, but WITHOUT
    ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
    FITNESS FOR A PARTICULAR PURPOSE. See the GNU Lesser General Public
    License for more details.

    You should have received a copy of the GNU Lesser General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef CPPSQL_RESOURCEMANAGER_H
#define CPPSQL_RESOURCEMANAGER_H

#include <map>
namespace cppsql {

template<typename Key, typename Resource, typename Caller>
class ResourceManager {
private:
    Caller* caller_;
    std::map<Key, Resource> data_;


public:
    ResourceManager(Caller* caller)
            :caller_(caller) { };
    Resource get_resource(const Key key);
};

}

template<typename Key, typename Resource, typename Caller>
Resource cppsql::ResourceManager<Key, Resource, Caller>::get_resource(const Key key)
{
    typename std::map<Key, Resource>::iterator it = this->data_.find(key);
    if (it==this->data_.end()) {
        Resource resource = caller_->create_resource(key);
        this->data_[key] = resource;
        return this->data_[key];
    }
    return it->second;
}

#endif //CPPSQL_RESOURCEMANAGER_H
