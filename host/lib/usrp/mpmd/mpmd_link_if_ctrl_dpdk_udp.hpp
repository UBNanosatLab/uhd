//
// Copyright 2018 Ettus Research, a National Instruments Company
//
// SPDX-License-Identifier: GPL-3.0-or-later
//

#ifndef INCLUDED_MPMD_XPORT_CTRL_DPDK_UDP_HPP
#define INCLUDED_MPMD_XPORT_CTRL_DPDK_UDP_HPP

#include "mpmd_link_if_ctrl_base.hpp"
#include <uhd/types/device_addr.hpp>
#include <uhdlib/transport/dpdk_zero_copy.hpp>

namespace uhd { namespace mpmd { namespace xport {

/*! UDP transport manager
 *
 * Opens UDP sockets
 */
class mpmd_link_if_ctrl_dpdk_udp : public mpmd_link_if_ctrl_base
{
public:
    mpmd_link_if_ctrl_dpdk_udp(
        const uhd::device_addr_t& mb_args
    );

    bool is_valid(
        const mpmd_link_if_mgr::xport_info_t& xport_info
    ) const;

    size_t get_mtu(
        const uhd::direction_t dir
    ) const;

private:
    const uhd::device_addr_t _mb_args;
    uhd::transport::uhd_dpdk_ctx &_ctx;
    const uhd::dict<std::string, std::string> _recv_args;
    const uhd::dict<std::string, std::string> _send_args;
    //! A list of IP addresses we can connect our CHDR connections to
    const std::vector<std::string> _available_addrs;
    //! MTU
    size_t _mtu;
};

}}} /* namespace uhd::mpmd::xport */

#endif /* INCLUDED_MPMD_XPORT_CTRL_DPDK_UDP_HPP */
