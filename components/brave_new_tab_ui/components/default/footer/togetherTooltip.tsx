// Copyright (c) 2020 The Brave Authors. All rights reserved.
// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this file,
// you can obtain one at http://mozilla.org/MPL/2.0/.

import * as React from 'react'

import styled from 'brave-ui/theme'

const Anchor = styled('div')`
  position: relative;
`

const Tooltip = styled('div').attrs({
  role: 'tooltip'
})`
  position: absolute;
  bottom: calc(100% + 20px);
  right: 0;
  min-width: 250px;
  border-radius: 4px;
  background: rgb(54, 154, 240);
  padding: 10px;
  color: white;
`

const Title = styled('h3')`
  font-size: 14px;
  margin-bottom: 4px;
`

const Body = styled('p')`
  font-size: 12px;
  margin-bottom: 4px;
  a {
    text-decoration: underline;
    color: inherit;
  }
`

const TogetherTooltip: React.FunctionComponent<{}> = function (props) {
  return (
    <Anchor>
      <Tooltip>
        <Title>Brave Together</Title>
        <Body>Start a private video call with your friends and colleagues.</Body>
        <Body><a href="https://brave.com/together">Learn more</a></Body>
      </Tooltip>
      { props.children }
    </Anchor>
  )
}

export default TogetherTooltip
