/* -*- c++ -*- */
/*
 * Copyright 2013 Free Software Foundation, Inc.
 *
 * This file is part of GNU Radio
 *
 * GNU Radio is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3, or (at your option)
 * any later version.
 *
 * GNU Radio is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with GNU Radio; see the file COPYING.  If not, write to
 * the Free Software Foundation, Inc., 51 Franklin Street,
 * Boston, MA 02110-1301, USA.
 */

#ifndef INCLUDED_BLOCKS_STREAM_TO_TAGGED_STREAM_H
#define INCLUDED_BLOCKS_STREAM_TO_TAGGED_STREAM_H

#include <gnuradio/blocks/api.h>
#include <gnuradio/sync_block.h>

namespace gr {
  namespace blocks {

    /*!
     * \brief Converts a regular stream into a tagged stream.
     * \ingroup blocks
     *
     * All this block does is add length tags in regular intervals.
     * It can be used to connect a regular stream to a gr::tagged_stream_block.
     */
    class BLOCKS_API stream_to_tagged_stream : virtual public gr::sync_block
    {
     public:
      typedef boost::shared_ptr<stream_to_tagged_stream> sptr;

      /*!
       * \param itemsize Item size
       * \param vlen Vector length of the input items. Note that one vector is one item.
       * \param packet_len Number of items per tagged stream packet. One tag is written every \p packet_len items.
       * \param len_tag_key Key of the length tag.
       */
      static sptr make(
	  size_t itemsize,
	  int vlen,
	  unsigned packet_len,
	  const std::string &len_tag_key
      );
    };

  } // namespace blocks
} // namespace gr

#endif /* INCLUDED_BLOCKS_STREAM_TO_TAGGED_STREAM_H */

